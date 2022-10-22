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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int n,b[1<<21],pw[22];
__int128 a[1<<21],one=1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	pw[0]=1;
	FOR(i,1,n)pw[i]=pw[i-1]*4;
	rep(i,0,1<<n){
		int t=__builtin_popcount(i);
		char c;
		cin>>c;
		a[i]=c-'0';
		a[i]*=pw[t];
	}
	rep(i,0,1<<n){
		int t=__builtin_popcount(i);
		char c;
		cin>>c;
		b[i]=c-'0';
		b[i]*=pw[t];
	}
	rep(i,0,n)rep(mask,0,1<<n)if(mask&(1<<i))a[mask]+=a[mask-(1<<i)],b[mask]+=b[mask-(1<<i)];
	rep(i,0,1<<n)a[i]=one*a[i]*b[i];
	rep(i,0,n)rep(mask,0,1<<n)if(mask&(1<<i))a[mask]-=a[mask-(1<<i)];
	rep(i,0,1<<n){
		int t=__builtin_popcount(i);
		int ans=a[i]/pw[t]%4;
		cout<<ans;
	}
	RE 0;
}