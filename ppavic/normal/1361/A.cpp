#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second 
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

const int N = 1e6 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

vector < int > v[N];
vector < int > rev[N];
int t[N], n, m, ima[N];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++){
		int a, b; scanf("%d%d", &a, &b);
		v[a].PB(b), v[b].PB(a);
	}
	for(int i = 1;i <= n;i++){
		scanf("%d", t + i);
		rev[t[i]].PB(i);
	}
	for(int i = 1;i <= n;i++){
		for(int x : v[i]) ima[t[x]] = 1;
		int k = 1;
		while(ima[k]) k++;
		for(int x : v[i]) ima[t[x]] = 0;
		if(k != t[i]){
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 1;i < N;i++){
		for(int x : rev[i]) printf("%d ", x);
	}
	printf("\n");
	return 0;
}