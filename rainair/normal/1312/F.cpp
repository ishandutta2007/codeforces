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

const int MAXN = 3e5 + 5;
/*
f[i][0] = mex(f[i-x][0],f[i-y][1],f[i-z][2])
f[i][1] = mex(f[i-x][0],f[i-z][2])
f[i][2] = mex(f[i-x][0],f[i-y][1])
f[i][j] <= 3
*/

int f[MAXN][3];

inline int mex(std::list<int> v){
	bool vis[4];CLR(vis,0);
	for(auto x:v){
		if(x < 3) vis[x] = 1;
	}
	FOR(i,0,3) if(!vis[i]) return i;
}

int m,x,y,z,st;
std::map<std::vector<int>,int> S;

inline void prework(){
	FOR(i,1,5){
		int a = std::max(0,i-x),b = std::max(0,i-y),c = std::max(0,i-z);
		f[i][0] = mex({f[a][0],f[b][1],f[c][2]});
		f[i][1] = mex({f[a][0],f[c][2]});
		f[i][2] = mex({f[a][0],f[b][1]});
	}
	S.clear();
	std::vector<int> v;
	FOR(i,1,5) FOR(j,0,2) v.pb(f[i][j]);
	S[v] = 1;
	m = 5;
	while(true){
		FOR(i,m+1,m+5){
			f[i][0] = mex({f[i-x][0],f[i-y][1],f[i-z][2]});
			f[i][1] = mex({f[i-x][0],f[i-z][2]});
			f[i][2] = mex({f[i-x][0],f[i-y][1]});
		}
		v.clear();
		FOR(i,m+1,m+5) FOR(j,0,2) v.pb(f[i][j]);
		if(S.count(v)){
			st = S[v];
			break;
		}
		S[v] = m+1;
		m += 5;
	}
}

inline int query(LL x,int o){
	if(x < 0) return 0;
	if(x < st) return f[x][o];
	x -= st;x %= (m-st+1);
	return f[x+st][o];
}

LL a[MAXN];

inline void Solve(){
	int n;scanf("%d%d%d%d",&n,&x,&y,&z);prework();
	FOR(i,1,n) scanf("%lld",a+i);
	// 0
	// 
	int sm = 0;
	FOR(i,1,n) sm ^= query(a[i],0);
	int ans = 0;
	FOR(i,1,n){
		int t1 = query(a[i]-x,0),t2 = query(a[i]-y,1),t3 = query(a[i]-z,2),t = query(a[i],0);
		if(sm == (t^t1)) ans++;
		if(sm == (t^t2)) ans++;
		if(sm == (t^t3)) ans++;
	}
	printf("%d\n",ans);
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}