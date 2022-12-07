#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

char buff[500010];
map<string, int> M;
string T[500010];
int read(){
	scanf("%s", buff);
	string s(buff);
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	if(M.find(s) == M.end()){
		int k = M.size();
		M[s] = k;
		T[k] = s;
	}
	return M[s];
}

int n, m;
PII w;
PII W[300010];
vector<int> E[300010];
vector<int> S;
bool vis[300010];

void dfs(int u){
	if(vis[u]) return;
	vis[u] = 1;
	for(int v : E[u]){
		dfs(v);
		W[u] = min(W[u], W[v]);
	}
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n) S.push_back(read());
	scanf("%d", &m);
	FWD(i,0,m){
		int a = read();
		int b = read();
		E[a].push_back(b);
	}
	FWD(i,0,M.size()){
		W[i].y = T[i].size();
		FWD(j,0,T[i].size()) if(T[i][j] == 'r') ++W[i].x;
	}
	FWD(r,0,20){
		FWD(i,0,M.size()) vis[i] = 0;
		for(int s : S) dfs(s);
	}
	for(int s : S){
		w.x += W[s].x;
		w.y += W[s].y;
	}
	cout << w.x << " " << w.y << endl;
	return 0;
}