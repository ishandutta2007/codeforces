/*

DP





ll int
 dp 










*/
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
void exgcd(int a,int b,int &x,int &y){
	if(!b){ x=1,y=0;return; }
	exgcd(b,a%b,x,y);
	int t=x;x=y,y=t-(a/b)*y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a1,b1,a2,b2,L,R,k,l;
	cin>>a1>>b1>>a2>>b2>>L>>R;
	exgcd(a1,a2,k,l);
	int gcd=__gcd(a1,a2),lcm=a1/gcd*a2;
	L=max(L,max(b1,b2));
	if((b2-b1)%gcd!=0||L>R){
		cout<<0;RE 0;
	}
	k*=(b2-b1)/gcd;
	k=(k%(a2/gcd)+a2/gcd)%(a2/gcd);
	int x=a1*k+b1;
	int ans=0;
	if(R>=x)ans+=(R-x)/lcm+1;
	if(L-1>=x)ans-=(L-1-x)/lcm+1;
	cout<<ans<<endl;
	return 0;
}