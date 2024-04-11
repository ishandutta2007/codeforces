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

const int MAXN = 1e6 + 5;
int ch[MAXN][26],fa[MAXN],n,rt = 1;

int dfn[MAXN],ts;
bool sp[MAXN];

inline void dfs(int v){
	if(sp[v]) ++ts;
	dfn[v] = ts;
	FOR(i,0,25){
		if(!ch[v][i]) continue;
		fa[ch[v][i]] = v;dfs(ch[v][i]);
	}
}

std::multiset<int> S;
int f[MAXN];

inline void dp(int v){
	if(v != 1){
		f[v] = f[fa[v]]+1;
		if(sp[v] && !S.empty()) f[v] = std::min(f[v],*S.begin()+dfn[v]);
	}
	S.insert(f[v]-dfn[v]+sp[v]);
	FOR(i,0,25){
		if(!ch[v][i]) continue;
		dp(ch[v][i]);
	}
	S.erase(S.find(f[v]-dfn[v]+sp[v]));
}

int a[MAXN],m;

int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		int f;char s[23];scanf("%d%s",&f,s);
		++f;ch[f][s[0]-'a'] = i+1;
	}
	scanf("%d",&m);
	FOR(i,1,m) scanf("%d",a+i),sp[a[i]+1] = 1;
	dfs(1);
	dp(1);
	FOR(i,1,m) printf("%d ",f[a[i]+1]);
	puts("");
	return 0;
}