#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
int n,k;
int ch[MAXN][26],rt = 1,tot = 1;
bool end[MAXN];
int sg[MAXN];
char str[MAXN];

inline void insert(char str[]){
	int n = strlen(str+1),v = rt;
	FOR(i,1,n){
		int o = str[i]-'a';
		if(!ch[v][o]) ch[v][o] = ++tot;
		v = ch[v][o];
	}
	end[v] = 1;
}

int f[MAXN],g[MAXN];

inline void dfs(int v){
	int c = 0;f[v] = 0;
	FOR(i,0,25){
		if(!ch[v][i]) continue;
		++c;dfs(ch[v][i]);
		if(!f[ch[v][i]]) f[v] = 1;
	}
	if(!c) f[v] = 0;
}

inline void dfs2(int v){
	int c = 0;g[v] = 0;
	FOR(i,0,25){
		if(!ch[v][i]) continue;
		++c;dfs2(ch[v][i]);
		if(!g[ch[v][i]]) g[v] = 1;
	}
	if(!c) g[v] = 1;
}

int main(){
	scanf("%d%d",&n,&k);
	FOR(i,1,n){
		scanf("%s",str+1);insert(str);
	}
	dfs(1);dfs2(1);
	if(f[1]&&g[1]){
		puts("First");
		return 0;
	}
	if(f[1] && !g[1]){
		puts(k&1?"First":"Second");
		return 0;
	}
	puts("Second");
	return 0;
}