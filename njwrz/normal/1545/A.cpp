#include<bits/stdc++.h>
#define ll long long
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
map<P<int,int>,int> mp;
int a[100005],b[100005];
void solve(){
	int n;
	mp.clear();
	cin>>n;
	FOR(i,1,n)cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	FOR(i,1,n)mp[MP(b[i],i&1)]++; 
	FOR(i,1,n){
		if(mp[MP(a[i],i&1)]>0){
			mp[MP(a[i],i&1)]--;
		}
		else {
			cout<<"NO\n";RE ;
		}
	}
	cout<<"YES\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}