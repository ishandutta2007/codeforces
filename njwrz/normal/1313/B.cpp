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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,a,b,ta,tb;
bool check1(int mid){
	int t=n*2-mid+1;
	t-=(mid>=ta)|(mid>=tb);
	t-=(ta+tb<=mid+1);
	RE (t>a+b);
}
bool check2(int mid){
	int t=1+mid;
	t+=(mid>=a)|(mid>=b);
	t+=(a+b<=mid+1);
	RE (t<=a+b);
}
void solve(){
	n,a,b;
	cin>>n>>a>>b;
	ta=n-a+1;tb=n-b+1;
	int ans,mid,l=0,r=n-1;
	while(r>=l){
		mid=(l+r)>>1;
		if(check1(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<n-ans<<' ';
	l=0;r=n-1;
	while(r>=l){
		mid=(l+r)>>1;
		if(check2(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans+1<<' ';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}