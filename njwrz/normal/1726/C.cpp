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
using namespace std;
int vis[200005];
int n;
void solve(){
	cin>>n;n*=2;
	V<int> s;
	s.PB(0);
	FOR(i,0,n)vis[i]=0;
	FOR(i,1,n){
		char c;
		cin>>c;
		if(c=='('){
			vis[s.back()]=1;
			s.PB(i);
		}else{
			s.pop_back();
		}
	}
	int ans=0;
	FOR(i,0,n){
		ans+=vis[i];
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}