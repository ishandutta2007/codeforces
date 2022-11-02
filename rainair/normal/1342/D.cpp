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

const int MAXN = 2e5 + 5;
std::vector<int> ans[MAXN];
int a[MAXN],n,k,cnt[MAXN],w[MAXN];
int id[MAXN];

int main(){
	scanf("%d%d",&n,&k);
	FOR(i,1,n) scanf("%d",a+i),cnt[a[i]]++,id[i] = i;
	FOR(i,1,k) scanf("%d",w+i);
	ROF(i,k,1) cnt[i] += cnt[i+1];
	int res = 0;
	FOR(i,1,k) res = std::max(res,(int)std::ceil(1.0*cnt[i]/w[i]));
	std::sort(a+1,a+n+1);
	int p = 0;
	FOR(i,1,n){
		ans[p].pb(a[i]);
		p++;p%=res;
	}
	printf("%d\n",res);
	FOR(i,0,res-1){
		printf("%d ",(int)ans[i].size());
		for(auto x:ans[i]) printf("%d ",x);
  		puts("");
	}
	return 0;
}