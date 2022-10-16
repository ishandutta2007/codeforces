#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

#define PB push_back
#define X first
#define Y second

using namespace std;

typedef long double ld;
typedef vector < ld > dist;

const int N = 1e3 + 50;

int n, m, u[N], d[N], dd[N], uk, mor;
vector < int > v[N], sve;
dist moj[N];

dist mul(dist A, dist B){
	dist C; C.resize((int)A.size() + (int)B.size() - 1);
	for(int i = 0;i < (int)A.size();i++){
		for(int j = 0;j < (int)B.size();j++){
			C[i + j] += A[i] * B[j];
		}
	}
	return C;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++){
		int sz; scanf("%d", &sz);
		for(;sz--;){
			int k; scanf("%d", &k);
			v[i].PB(k), sve.PB(k);
		}
	}
	sort(sve.rbegin(), sve.rend());
	int cut = sve[n - 1];
	for(int i = 0;i < m;i++){
		u[i] = (int)v[i].size();
		for(int x : v[i])
			d[i] += (x >= cut), dd[i] += (x > cut);
		for(int j = 0;j <= d[i];j++)
			moj[i].PB(0);
		ld ch = 1;
		for(int j = 0;j < dd[i];j++)
			ch = ch * (j + 1) / (u[i] - j);
		moj[i][dd[i]] = ch;
		if(d[i] > dd[i]){
			ch = ch * d[i] / (u[i] - d[i] + 1);
			moj[i][d[i]] = ch;
		}
		uk += d[i];
		mor += dd[i];
	}
	dist sad = {1.0};
	for(int i = 0;i < m;i++){
		sad = mul(sad, moj[i]);
		if(i < uk - n){
			for(ld &x : sad){
				x *= (i + 1) / (ld)(uk - mor - i);
			}
		}
	}
	printf("%.10Lf\n", sad[n]);
	return 0;
}