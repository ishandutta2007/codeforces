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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int ans[1005][1005];
int n,a[1005][1005],k;
int nxt[1005][1005],hav[1005][1005];
void solve(){
	cin>>n>>k;k=n-k+1;
	FOR(i,1,n)FOR(j,1,n){
		ans[i][j]=1;
		char c;
		cin>>c;
		a[i][j]=c-'0';ans[i][j]=1;
	} 
	for(int i=n;i>=1;i--)for(int j=n;j>=1;j--){
		if(a[i][j])nxt[i][j]=0;
		else if(i<n&&j<n)nxt[i][j]=((nxt[i+1][j+1]==-1)?-1:(nxt[i+1][j+1]+1));
		else nxt[i][j]=-1;
	}
	FOR(i,1,k){
		FOR(j,1,k){
			int t=max(hav[i-1][j],hav[i][j-1]);
			if(i+t>n||j+t>n||nxt[i+t][j+t]==-1){
				cout<<"No\n";RE;
			}
			t=nxt[i+t][j+t]+t;
			ans[i+t][j+t]=0;
			hav[i][j]=t;
		}
	}
	cout<<"Yes\n";
	FOR(i,1,n){
		FOR(j,1,n)cout<<ans[i][j];
		cout<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}