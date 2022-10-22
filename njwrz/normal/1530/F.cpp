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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int a[22][22],b[22][22],n,mod=31607; 
int POW(int x,int y){
	if(!y)RE 1;
	int t=POW(x,y/2);
	t=t*t%mod;
	if(y&1){
		RE t*x%mod;
	}else RE t;
}
int val[1<<21],p[21],mp[1<<21],v[21][1<<21];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int t=POW(10000,mod-2);
	rep(i,0,n)rep(j,0,n)cin>>b[i][j],b[i][j]=b[i][j]*t%mod;
	int ans=0;
	rep(i,0,n)mp[1<<i]=i;
	FOR(t1,0,1){
		FOR(t2,0,1){
			int mul=1;
			rep(i,0,n){
				rep(j,0,n)a[i][j]=b[i][j];
			}
			if(t1){
				rep(i,0,n)mul=mul*a[i][i]%mod,a[i][i]=1;
			}
			if(t2){
				rep(i,0,n)mul=mul*a[i][n-i-1]%mod,a[i][n-i-1]=1;
			}
			rep(i,0,n){
				p[i]=1;
				rep(j,0,n)p[i]=p[i]*a[j][i]%mod;
				v[i][0]=1;
				rep(j,1,1<<n)v[i][j]=v[i][j-(j&-j)]*a[i][mp[j&-j]]%mod;
			}
			int sum=0;
			rep(i,0,1<<n){
				if(i)val[i]=val[i-(i&-i)]*p[mp[i&-i]]%mod;
				else val[i]=mul;
				int now=val[i];
				rep(j,0,n)now=now*(1+mod-v[j][((1<<n)-1)^i])%mod;
				if(__builtin_popcount(i)&1){
					sum=(sum-now+mod)%mod;
				}else sum=(sum+now)%mod;
			}
			if(t1^t2){
				ans=(ans-sum+mod)%mod;
			}else ans=(ans+sum)%mod;
		}
	}
	cout<<(mod+1-ans)%mod;
	RE 0;
}