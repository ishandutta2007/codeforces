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
int a[300005],cnt[1000005];
int p[1005],m;
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];
		for(int j=1;j<=m&&p[j]*p[j]<=a[i];j++){
			while(a[i]%(p[j]*p[j])==0)a[i]/=p[j]*p[j];
		}
		cnt[a[i]]++;
//		cout<<a[i]<<'\n';
	}
	int ans1=0,ans0=0,sum=cnt[1];
	FOR(i,1,n){
		if(cnt[a[i]]){
			gmax(ans1,cnt[a[i]]);
			gmax(ans0,cnt[a[i]]);
			if(!(cnt[a[i]]&1)&&a[i]!=1){
				sum+=cnt[a[i]];
				gmax(ans1,sum);
			}
			cnt[a[i]]=0;
		}
	}
	int q;cin>>q;
	FOR(i,1,q){
		int x;
		cin>>x;
		if(x){
			cout<<ans1<<'\n';
		}else cout<<ans0<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	FOR(i,2,997){
		bool ff=1;
		int t=i;
		for(int j=2;j*j<=t;j++){
			if(i%j==0){
				ff=0;break;
			}
		}
		if(ff)p[++m]=i;
	}
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}