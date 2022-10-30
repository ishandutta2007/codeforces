#include<bits/stdc++.h>
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
int n,m,a[100005],b[100005];
void solve(){
	int num;
	cin>>n>>num;
	FOR(i,1,n)cin>>a[i];
	cin>>m;
	FOR(i,1,m)cin>>b[i];
	V<P<int,int> > va;
	FOR(i,1,n){
		if(a[i]%num!=0){
			if(va.empty()||va.back().F!=a[i])va.PB(MP(a[i],a[i]));
			else va.back().S+=a[i];
		}else{
			int t=a[i];
			while(t%num==0)t/=num;
			if(va.empty()||va.back().F!=t){
				va.PB(MP(t,a[i]));
			}else va.back().S+=a[i];
		}
	}
	V<P<int,int> > vb;
	FOR(i,1,m){
		if(b[i]%num!=0){
			if(vb.empty()||vb.back().F!=b[i])vb.PB(MP(b[i],b[i]));
			else vb.back().S+=b[i];
		}else{
			int t=b[i];
			while(t%num==0)t/=num;
			if(vb.empty()||vb.back().F!=t){
				vb.PB(MP(t,b[i]));
			}else vb.back().S+=b[i];
		}
	}
//	for(auto u:vb)cout<<u.F<<' '<<u.S<<'\n';
	if(va==vb){
		cout<<"Yes\n";
	}else cout<<"No\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}