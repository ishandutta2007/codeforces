/*

DP





ll int
 dp 










*/
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
bool f[100005];
void out(){
	cout<<"NO";
	exit(0);
}
int fa[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	f[1]=1;
	FOR(i,2,n+1){
		if(!(i&1)&&f[i/2])f[i]=1;
	}
	int maxi=(n-3)/2;
	gmax(maxi,0);
	if(!(n&1)||n==9&&k==2||k>maxi||f[n+1]&&k==1||!f[n+1]&&k==0)out();
	if(k==0){
		cout<<"YES\n";
		FOR(i,1,n){
			cout<<i/2<<' ';
		}
		RE 0;
	}
	int t=2*(k-1);
	for(int i=1;i<t;i+=2){
		fa[i+1]=i;
		fa[i]=max(i-2,0);
	}
	fa[t+1]=max(0,t-1);
	FOR(i,2,n-t){
		fa[i+t]=i/2+t;
	}
	if(f[n-t+1]){
		fa[n-1]=fa[n]=2;
	} 
	cout<<"YES\n";
	FOR(i,1,n)cout<<fa[i]<<' ';
	RE 0;
}