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

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

vector < int > v[N];
vector < int > gore[N], dolje[N];
set < pair < int, pair < int, int > > > S[N];

int dep[N], bio[N], dobar = 1, akt[N];
int moze0[N], moze1[N], pokaz[N], root;
int n, m;

void dfs(int x){
	bio[x] = 1; akt[x] = 1;
	for(int y : v[x]){
		if(bio[y]){
			if(!akt[y]) dobar = 0;
			gore[x].PB(y); 
		}
		else{
			dep[y] = dep[x] + 1;
			dfs(y);
			dolje[x].PB(y);
		}
	}
	akt[x] = 0;
}

void dfs2(int x){
	for(int y : gore[x])
		S[x].insert({-dep[y], {y, x}});
	for(int y : dolje[x]){
		dfs2(y);
		if(S[y].size() > S[x].size())
			swap(S[x], S[y]);
		for(pair < int, pair < int, int > > z : S[y])
			S[x].insert(z);
		S[y].clear();
	}
	for(;!S[x].empty() && (S[x].begin()->X) <= -dep[x];S[x].erase(S[x].begin()));
	moze0[x] = ((int)S[x].size() == 1 || x == root);
	if(moze0[x] && (x != root))
		pokaz[x] = S[x].begin()->Y.X;
}

void dfs3(int x){
	moze1[x] = (x == root);
	if(x != root && moze0[x] && moze1[pokaz[x]])
		moze1[x] = 1;
	for(int y : dolje[x])
		dfs3(y);
}

void ocisit(){
	for(int i = 1;i <= n;i++){
		gore[i].clear(); S[i].clear();
		dolje[i].clear();
		moze0[i] = 0, moze1[i] = 0; 
		bio[i] = 0; dep[i] = 0; akt[i] = 0;
		pokaz[i] = 0; dep[i] = 0;
	}
}

void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++){
		int x, y; scanf("%d%d", &x, &y);
		v[x].PB(y);	
	}
	for(int i = 0;i < 80;i++){
		ocisit();
		root = (rand() * rand() % n + n) % n + 1;
		dep[root] = 0;dobar = 1; dfs(root);
		if(!dobar) continue;
		moze0[root] = 1; moze1[root] = 1;
		dfs2(root);
		dfs3(root);
		int cnt = 0;
		for(int i = 1;i <= n;i++)
			cnt += moze0[i] * moze1[i] ;
		if(5 * cnt < n){
			continue;
		}
		for(int i = 1;i <= n;i++)
			if(moze0[i] && moze1[i])
				printf("%d ", i);
		printf("\n");
		for(int i = 1;i <= n;i++)
			v[i].clear();
		return;
		
	}
	for(int i = 1;i <= n;i++)
		v[i].clear();
	printf("-1\n");
	return;
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}