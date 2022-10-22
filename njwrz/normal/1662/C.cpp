#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
using namespace __gnu_pbds;
#define mod 998244353 
struct matrix{
	int n,m;
	int a[205][205];
};
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
matrix operator *(matrix x,matrix y){
	matrix re;
	re.n=x.n;re.m=y.m;
	FOR(i,0,re.n){
		FOR(j,0,re.m){
			re.a[i][j]=0;
			FOR(k,0,x.m)add(re.a[i][j],x.a[i][k]*y.a[k][j]%mod);
		}
	}
	RE re;
}
matrix POW(matrix x,int y){
	matrix re;
	FILL(re.a,0);
	re.n=re.m=x.n;
	FOR(i,1,x.n)re.a[i][i]=1;
	while(y){
		if(y&1)re=re*x;
		x=x*x;
		y/=2;
	}
	RE re;
}
int n,m,k;
matrix mul;
V<int> v[205];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	mul.n=2*n,mul.m=2*n;
	FOR(i,1,n)mul.a[i+n][i]=1;
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
		mul.a[x+n][y+n]=1;
		mul.a[y+n][x+n]=1;
	}
	FOR(i,1,n)mul.a[i][i+n]=mod-v[i].size()+1;
	matrix now=POW(mul,k-1);
	FOR(i,1,n)mul.a[i][i+n]=mod-v[i].size();
	now=now*mul;
	int ans=0;
	FOR(i,1,n){
		add(ans,now.a[i+n][i+n]);
	}
	cout<<ans;
	RE 0;
}