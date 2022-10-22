#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define double long double
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
int c,h;
double t;
double check(int a){
	RE 1.0*((a+1)*h+a*c)/(2*a+1.0);
}
void solve(){
	cin>>h>>c>>t;
	int l=0,r=1e10,mid,ans;
	while(r>=l){
		mid=(r+l)>>1;
		if(check(mid)<t){
			r=mid-1;
		}else{
			l=mid+1;
			ans=mid;
		}
	}
	double ans1=abs((h+c)/2.0-t),ans2=abs(check(ans)-t),ans3=abs(t-check(ans+1));
	double now=min(ans1,min(ans2,ans3));
	if(!ans){
		if(ans2==now){
			cout<<ans*2+1;
		}else if(ans1==now){
			cout<<2;
		}else{
			cout<<ans*2+3;
		}
	}else{
		if(ans1==now){
			cout<<2;
		}else if(ans2==now){
			cout<<ans*2+1;
		}else {
			cout<<ans*2+3;
		}
	}
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