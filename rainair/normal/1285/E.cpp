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

std::vector<int> S;
int n;
int l[MAXN],r[MAXN];
int d[MAXN],dd[MAXN];

inline void Solve(){
	scanf("%d",&n);S.clear();
	FOR(i,1,n){
		scanf("%d%d",l+i,r+i);S.pb(l[i]);S.pb(r[i]);
	}
	std::sort(all(S));S.erase(std::unique(all(S)),S.end());
	FOR(i,1,n) l[i] = std::lower_bound(all(S),l[i])-S.begin()+1,r[i] = std::lower_bound(all(S),r[i])-S.begin()+1;
	int m = 0;
	FOR(i,1,n){
		l[i] <<= 1;r[i] <<= 1;m = std::max(m,r[i]);
//		printf("%d %d\n",l[i],r[i]);
	}
	FOR(i,1,n) d[l[i]]++,d[r[i]+1]--;
	FOR(i,1,m) d[i] += d[i-1];d[m+1] = 0;d[m+2] = -1;
	FOR(i,1,m) dd[i] = dd[i-1]+(d[i]==1&&d[i-1]!=1)+(d[i]==1&&d[i+1]!=1);
	int ans = -1;
	FOR(i,1,n){
		ans = std::max(ans,(dd[r[i]]-dd[l[i]-1])/2-(d[l[i]]==1)-(d[r[i]]==1));
	}
	int ori = 1;
	FOR(i,0,m+1) ori += (d[i]==0&&d[std::max(0,i-1)]!=0)+(d[i]==0&&d[i+1]!=0);
	ori >>= 1;--ori;
	printf("%d\n",ans+ori);
	FOR(i,1,m+2) d[i] = dd[i] = 0;
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}
/*
1
2
3 4
-3 2
*/