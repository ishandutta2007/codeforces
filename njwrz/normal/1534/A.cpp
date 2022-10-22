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
void solve(){
	int n,m;
	cin>>n>>m;
	int t=-1;
	bool ff=1;
	char c;
	FOR(i,1,n){
		FOR(j,1,m){
			char c;
			cin>>c;
			if(c=='.')continue;
			int now=(i&1)^(j&1)^(c=='R');
			if(t!=-1&&t!=now){
				ff=0;
			}
			t=now;
		}
	}
	if(!ff){
		cout<<"NO\n";RE ;
	}
	if(t==-1)t=1;
	cout<<"YES\n"; 
	FOR(i,1,n){
		FOR(j,1,m){
			if(t^(i&1)^(j&1)){
				cout<<'R';
			}else cout<<'W';
		}
		cout<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}