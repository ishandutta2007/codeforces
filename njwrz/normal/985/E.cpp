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
V<int> v;
int n,k,d;
int a[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>d;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	v.PB(0);
	int t;
	FOR(i,k,n){
		t=*(upper_bound(ALL(v),i-k)-1);
		if(a[i]-a[t+1]<=d)v.PB(i);
	} 
	if(v.back()==n)cout<<"YES";else cout<<"NO";
	RE 0;
}