#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;

const int mod=998244353;
int sum[200005];
int fr[200005],to[200005];
bool burn[200005];
int n;
void update(int x,int y){
	while(x){
		(sum[x]+=y)%=mod;
		x-=x&-x;
	}
}
int get(int x){
	int re=0;
	while(x<=n){
		(re+=sum[x])%=mod;
		x+=x&-x;
	} 
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int ans=0;
	FOR(i,1,n){
		cin>>fr[i]>>to[i]>>burn[i];
		int t=lwb(fr+1,fr+i+1,to[i])-fr;
		int cost;
		if(t==i)cost=fr[i]-to[i];
		else cost=fr[t]-to[i]+get(t)+fr[i]-fr[i-1];
		cost=(cost%mod+mod)%mod;
		update(i,cost);
		if(i>1)update(i-1,fr[i]-fr[i-1]);
		if(burn[i]==1)ans+=cost+fr[i]-fr[i-1];else ans+=fr[i]-fr[i-1];
		ans=(ans%mod+mod)%mod;
//		cout<<"  "<<t<<' '<<cost<<' '<<ans<<'\n';
	}
	ans++;
	cout<<(ans%mod+mod)%mod;
	RE 0;
}