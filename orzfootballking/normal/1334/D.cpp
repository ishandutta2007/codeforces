#pragma GCC optimize("Ofast")
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
	int n,l,r;
	cin>>n>>l>>r;
	int sum=0,start=0,t;
	FOR(i,1,n){
		t=(n-i)*2;
		if(sum+t>=l){
			start=i;break;	
		}
		sum+=t;
	}
	sum++;
	if(!start){
		cout<<"1\n";RE;
	}
	bool f=0;
	if(r==(n-1)*n+1)r--,f=1;
	int i=start,j=start+1;
	while(sum<=r){
		if(sum>=l)cout<<i<<' ';
		sum++;
		if(sum>=l&&sum<=r)cout<<j<<' ';
		sum++;
		if(j==n)i++,j=i+1;else j++;
	}
	if(f)cout<<1;
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}