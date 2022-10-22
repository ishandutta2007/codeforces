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
int p[1000005],n,cnt[4];
bool vis[1000005];
int mod=1e9+7;
int solve(int ans){
	int t=min(cnt[1],cnt[2]);
	ans+=t;
	cnt[1]-=t;
	cnt[2]-=t;
	if(cnt[1])ans+=cnt[1]/3*2;
	if(cnt[2])ans+=cnt[2];
	cnt[1]+=t;
	cnt[2]+=t;
	RE ans;
}
void solve(){
	FILL(cnt,0);
	cin>>n;
	FOR(i,1,n)vis[i]=0;
	FOR(i,1,n)cin>>p[i];
	V<int> v;
	FOR(i,1,n){
		if(!vis[i]){
			int t=i;vis[i]=1;int now=1;
			t=p[t];
			while(t!=i){
				vis[t]=1;
				now++;
				t=p[t];
			}
			v.PB(now);
		}
	}
	if(n%3==0){
		int ans=0;
		int mul=1;
		FOR(i,1,n/3)mul=mul*3%mod;
		cout<<mul<<' ';
		for(auto u:v)cnt[u%3]++,ans+=(u-1)/3;
		cout<<solve(ans);
	}else if(n%3==1){
		int ans=0;
		int mul=1;
		rep(i,1,n/3)mul=mul*3%mod;
		mul=mul*4%mod;
		cout<<mul<<' ';
		bool f=0;
		for(auto u:v){
			cnt[u%3]++;
			ans+=(u-1)/3;
			if(u%3==1&&u!=1){
				f=1;
			}
		}
		int mini=1e15;
		if(f){
			ans--;cnt[1]--;
			gmin(mini,solve(ans));
			ans++;cnt[1]++;
		}
		if(cnt[2]>1){
			cnt[2]-=2;
			gmin(mini,solve(ans));
			cnt[2]+=2;
		}
		if(cnt[2]>0&&cnt[1]>1){
			ans++;
			cnt[2]--;
			cnt[1]-=2;
			gmin(mini,solve(ans));
			cnt[2]++;
			cnt[1]+=2;
			ans--;
		}
		if(cnt[0]>0&&cnt[1]>0){
			cnt[0]--;
			cnt[1]--;
			ans++;
			gmin(mini,solve(ans));
			cnt[0]++;
			cnt[1]++;
			ans--;
		}
		if(cnt[1]>3){
			cnt[1]-=4;
			ans+=2;
			gmin(mini,solve(ans));
			ans-=2;
			cnt[1]+=4;
		}
		cout<<mini;
	}else{
		int mul=1;
		int ans=0;
		FOR(i,1,n/3){
			mul=mul*3%mod;
		}
		mul=mul*2%mod;
		for(auto u:v)cnt[u%3]++,ans+=(u-1)/3;
		cout<<mul<<' ';
		if(cnt[2]){
			cnt[2]--;
		}else{
			cnt[1]-=2;
			ans++;
		}
		cout<<solve(ans);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	FOR(i,1,t){
		solve();
		cout<<'\n';
	}
	RE 0;
}