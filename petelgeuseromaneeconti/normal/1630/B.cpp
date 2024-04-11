#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
mt19937 rng(233);
const int N=200005;
int T,n,K,a[N],b[N],s[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	rep(tc,1,T){
		//D("tc=%d\n",tc);
		scanf("%d%d",&n,&K);
		//n=rng()%100+1,K=rng()%n+1;
		fill(b+1,b+n+1,0);
		rep(i,1,n)scanf("%d",&a[i]);
		//rep(i,1,n)a[i]=rng()%n+1;
		rep(i,1,n)++b[a[i]];
		int least=(n+K+1)/2; // least>=n-least+K  2least>=n+K least>=(n+K)/2
		rep(i,1,n)s[i]=s[i-1]+b[i];
		tuple<int,int,int>ans={1e9,-1,-1};
		for(int i=1,j=1;i<=n;++i){
			while(j<=n&&s[j]-s[i-1]<least)++j;
			// [i,j] ok
			if(j<=n&&s[j]-s[i-1]>=least){
				ans=min(ans,{j-i+1,i,j});
			}
		}
		int l=get<1>(ans),r=get<2>(ans);
		printf("%d %d\n",l,r);
		int tt=0,last=0;
		vector<pair<int,int> >v;
		for(int i=1;i<=n;++i){
			if(a[i]>=l&&a[i]<=r){
				tt+=1;
			}else{
				tt-=1;
			}
			if(tt==1){
				v.eb(last+1,i);
				last=i;
				tt=0;
			}
		}
		assert(SZ(v)>=K);
		v.resize(K);
		v.back().second=n;
		rep(i,0,K-1)printf("%d %d\n",v[i].first,v[i].second);
	}
	return 0;
}