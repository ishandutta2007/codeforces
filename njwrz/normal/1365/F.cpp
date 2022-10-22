#pragma GCC optimize("Ofast")
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
int n,a[505],b[505];
map<P<int,int>,int> m;
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>b[i];
	if(n&1){
		if(a[n/2+1]!=b[n/2+1]){
			cout<<"No\n";RE;
		}
	}
	m.clear();
	FOR(i,1,n/2){
		if(a[i]>a[n-i+1])swap(a[i],a[n-i+1]);
		if(b[i]>b[n-i+1])swap(b[i],b[n-i+1]); 
		m[MP(a[i],a[n-i+1])]++;
	}
	FOR(i,1,n/2){
		if(m[MP(b[i],b[n-i+1])]==0){
			cout<<"No\n";RE;
		}else m[MP(b[i],b[n-i+1])]--;
	}
	cout<<"Yes\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}