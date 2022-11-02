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
int cnt[3005];
int it[3005][3005],len,dp[3005][5],t[4]={0,1,0,1},p[3005];
void solve(){
	int n;
	cin>>n;
	int x;
	FOR(i,1,n)cnt[i]=0;
	FOR(i,1,n){
		cin>>x;
		it[x][++cnt[x]]=i;
	}
	int ans=0;
	FOR(i,1,n){
		FOR(j,1,n){
			if(i==j){
				if(cnt[i]>3){
					ans+=cnt[i]*(cnt[i]-1)*(cnt[i]-2)*(cnt[i]-3)/24;
				}
				continue;
			}
			if(cnt[i]<2||cnt[j]<2)continue;
			int l1=1,l2=1;len=cnt[i]+cnt[j];
			FOR(k,1,len){
				if(it[i][l1]>it[j][l2]&&l2<=cnt[j]||l1>cnt[i]){
					p[k]=1;l2++;
				}else p[k]=0,l1++;
			}
			dp[0][0]=1;
			FOR(k,1,len){
				dp[k][0]=dp[k-1][0];
				FOR(now,1,4){
					dp[k][now]=dp[k-1][now];
					if(t[now-1]==p[k])dp[k][now]+=dp[k-1][now-1];
				}
			}
			ans+=dp[len][4];
		}
	}
	cout<<ans<<'\n'; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}