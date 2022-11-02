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

const int MAXN = 5e5 + 5;
const int ha = 998244353;
int l[MAXN],r[MAXN],t[MAXN],_[MAXN],a[MAXN];
int n,k,m;
int cf[MAXN];
int lim[MAXN];
int f[MAXN];

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

inline int work(){
	FOR(i,1,n+1) cf[i] = lim[i] = f[i] = 0;
	FOR(i,1,m) if(t[i]) cf[l[i]]++,cf[r[i]+1]--;
	FOR(i,1,n+1) cf[i] += cf[i-1];
	FOR(i,1,m){
		if(!t[i]){
			lim[r[i]+1] = std::max(lim[r[i]+1],l[i]);
		}
	}
	FOR(i,1,n+1) lim[i] = std::max(lim[i-1],lim[i]);
	f[0] = 1;int sm = 1,tp = 0;
	FOR(i,1,n+1){
		while(tp < lim[i]) add(sm,ha-f[tp]),++tp;
		if(cf[i]) f[i] = 0;
		else f[i] = sm;
		add(sm,f[i]);
	}
	int res = 0;
	FOR(i,lim[n],n) add(res,f[i]);
	return f[n+1];
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	FOR(i,1,m) scanf("%d%d%d",l+i,r+i,_+i);
	int ans = 1;
	FOR(i,0,k-1){
		FOR(j,1,m) t[j] = (_[j]>>i)&1;
		// int t = work();
		ans = 1ll*ans*work()%ha;
	}
	printf("%d\n",ans);
	return 0;
}
/*
0,pos[i]i0
f[i] i0
f[i] = \sum f[j] (pos[i] <= j < i)
*/