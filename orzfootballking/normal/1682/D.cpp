#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
using namespace __gnu_pbds;
char c[200005];
int n;
void solve(){
	cin>>n;
	int cnt=0;
	FOR(i,1,n){
		cin>>c[i];
		cnt+=c[i]=='1';
	}
	if((cnt&1)||cnt==0){
		cout<<"NO\n";RE;
	}
	cout<<"YES\n";
	V<P<int,int> > ans;
	int it=-1;
	FOR(i,1,n)if(c[i]=='1')it=i+1;
	if(it>n)it=1;
	FOR(i,1,n)if(i!=it){
		int lst=i-1;
		if(!lst)lst=n;
		if(c[lst]=='1'){
			ans.PB(MP(i,it));
		}else ans.PB(MP(i,lst));
	}
	for(auto u:ans)cout<<u.F<<' '<<u.S<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}