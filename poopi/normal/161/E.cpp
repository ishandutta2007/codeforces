										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>
#define Max 100000

int n, p10[6];
int nex[Max];
bool npr[Max];
vector <int> pr;
vector <int> dig[Max];
int mat[6][6];

void find_prime(){
	for(int i = 2; i < Max; i++){
		if(!npr[i]){
			nex[i] = pr.size();
			pr.push_back(i);
			for(int j = 2 * i; j < Max; j += i)
				npr[j] = true;
		}
	}
}

int bt(int idx){
	if(idx == n)
		return 1;
	int mn = 0;
	for(int i = 0; i < n; i++)
		mn = mn * 10 + mat[idx][i];
	int mx = mn + p10[n - idx];
	int pnt = nex[mn];
	int cnt = 0;
	while(pnt < pr.size() && pr[pnt] < mx){
		for(int i = n - 1; i >= idx; i--)
			mat[idx][i] = mat[i][idx] = dig[pnt][n - i - 1];
		cnt += bt(idx + 1);
		for(int i = n - 1; i >= idx; i--)
			mat[idx][i] = mat[i][idx] = 0;
		pnt++;
	}
	return cnt;
}

int main(){
	find_prime();
	for(int i = 0; i < pr.size(); i++){
		int t = pr[i];
		for(int j = 0; j < 5; j++){
			dig[i].push_back(t % 10);
			t /= 10;
		}
	}
	nex[Max - 1] = pr.size();
	for(int i = Max - 2; i >= 0; i--)
		if(npr[i])
			nex[i] = nex[i + 1];
	p10[0] = 1;
	for(int i = 1; i < 6; i++)
		p10[i] = p10[i - 1] * 10;
	int T, p;
	for(cin >> T; T--; ){
		cin >> p;
		int arr[6];
		n = 0;
		while(p10[n] <= p)
			n++;
		memset(mat, 0, sizeof mat);
		for(int i = n - 1; i >= 0; i--, p /= 10)
			mat[0][i] = mat[i][0] = p % 10;
		cout << bt(1) << endl;
	}
	return 0;
}