#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,a[100005];
void solve(){
	int m;
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	if(m<a[n]){
		if((*lower_bound(a+1,a+n+1,m))==m){
			cout<<"1\n";
		}else cout<<"2\n";
		RE;
	}
	cout<<m/a[n]+(m%a[n]!=0)<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}