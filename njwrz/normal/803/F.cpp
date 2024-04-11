/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
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
int cnt[100005];
int in[100005],ans,pow_2[100005],mod=1e9+7;
bool f[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	FOR(i,2,100000){
		if(!in[i]){
			for(int j=i;j<=100000;j+=i){
				in[j]++;
				if(j%(i*i)==0)f[j]=1;
			}
		}
	}
	int n,x;
	cin>>n;
	pow_2[0]=1;
	FOR(i,1,n){
		pow_2[i]=pow_2[i-1]*2%mod;
		cin>>x;
		cnt[x]++;
	}ans=pow_2[n]-1;
	FOR(i,2,100000){
		if(f[i])continue;
		int tot=0;
		for(int j=i;j<=100000;j+=i){
			tot+=cnt[j];
		}
//		if(tot>0){
//			cout<<i<<' '<<tot<<'\n';
//		}
		if(in[i]&1){
			ans=(ans-(pow_2[tot]-1)+mod)%mod;
		}else ans=(ans+(pow_2[tot]-1))%mod;
	}
	cout<<ans;
	RE 0;
}