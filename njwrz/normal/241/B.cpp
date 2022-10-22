#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define sz(x) ((int)x.size())
using namespace std;
const int mod=1e9+7;
int a[50005];
ll n;
ll m;
int siz[2000005],ch[2000005][2],sum[2000005];
int root,cnt,pos[50005],ans,cntb[30];
signed main(){
	root=cnt=1;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	m=n*(n-1)/2-m;
	m=m*2+n;
	ll tm=m;
	ll tot=0;
	FOR(i,1,n){
		cin>>a[i];
		rep(j,0,30)if(a[i]&(1<<j))cntb[j]++;
		int now=root;
		for(int j=29;j>=0;j--){
			siz[now]++;
			int t=(a[i]>>j)&1;
			if(!ch[now][t]){
				ch[now][t]=++cnt;
			}
			now=ch[now][t];
		}
		siz[now]++;
	}
	FOR(i,0,29)tot=(tot+1ll*cntb[i]*(n-cntb[i])%mod*(1<<i))%mod;
	FOR(i,1,n)pos[i]=root;
	for(int i=29;i>=0;i--){
		ll sum=0;
		FOR(j,1,n)if(pos[j]){
			int t=(a[j]>>i)&1;
			sum+=siz[ch[pos[j]][t]];
		}
		if(sum>=m){
			FOR(j,1,n){
				pos[j]=ch[pos[j]][(a[j]>>i)&1];
			}
		}else{
			m-=sum;
			ans+=(1<<i);
			FOR(j,1,n){
				pos[j]=ch[pos[j]][!((a[j]>>i)&1)];
			}
		}
	}
	ll sum2=0;
	ll hav=0;
	FOR(b,0,29){
		FOR(i,1,cnt)sum[i]=0;
		FOR(i,1,n)if(a[i]&(1<<b)){
			int now=root;
			for(int j=29;j>=0;j--){
				now=ch[now][(a[i]>>j)&1];
				sum[now]++;
			}
		}
		FOR(i,1,n){
			int now=root;
			for(int j=29;j>=0;j--){
				int t=(a[i]>>j)&1;
				if(ans&(1<<j)){
					if(a[i]&(1<<b)){
						sum2+=(0ll+siz[ch[now][t]]-sum[ch[now][t]])<<b;
					}else{
						sum2+=(0ll+sum[ch[now][t]])<<b;
					}
					if(!b)hav+=siz[ch[now][t]];
					now=ch[now][!t];
				}else now=ch[now][t];
			}
			if(!b)hav+=siz[now];
			if(a[i]&(1<<b)){
				sum2+=(siz[now]-sum[now]+0ll)<<b;
			}else{
				sum2+=(sum[now]+0ll)<<b;
			}
		}
	}
	sum2%=mod;
	sum2=(sum2-1ll*(hav-tm)*ans%mod+mod)%mod;
	cout<<(tot-sum2*(mod+1)/2%mod+mod)%mod;
	RE 0;
}