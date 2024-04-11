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
int n,m;
P<int,P<int,int> > p[155];
struct matrix{
	int len;
	bitset<155> a[155];
};
matrix emp;
matrix operator *(const matrix &x,const matrix &y){
	matrix re=emp;re.len=x.len;
	FOR(i,1,x.len){
		FOR(j,1,y.len)if(x.a[i][j]){
			re.a[i]|=y.a[j];
		}
	}
	RE re;
}
matrix base;
matrix POW(matrix x,int y){
	matrix re=base;
	while(y){
		if(y&1){
			re=re*x;
		}
		x=x*x;
		y/=2;
	}
	RE re;
}
matrix mul;
int to[155][155];
int vis[155],tt[155];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,m){
		cin>>p[i].S.F>>p[i].S.S>>p[i].F;
	}
	base.len=n+1;
	FOR(i,1,153){
		base.a[i][i]=1;
	}
	sort(p+1,p+m+1);
	matrix now=base;
	FOR(i,2,153)now.a[i][i]=0;
	mul.len=n+1;mul.a[n][n+1]=1;mul.a[n+1][n+1]=1;
	FOR(i,1,m){
		matrix lst=now;
		int ti=p[i].F-p[i-1].F;
		now=now*POW(mul,ti);
		to[p[i].S.F][p[i].S.S]=1;
		mul.a[p[i].S.F][p[i].S.S]=1;
		if(now.a[1][n]||now.a[1][n+1]){
			now=lst;
			FOR(j,1,n)vis[j]=now.a[1][j];
			int tim=p[i-1].F;
			while(1){
				tim++;
				FOR(j,1,n)FOR(k,1,n)if(to[j][k])tt[k]=1;
				FOR(j,1,n)vis[j]=tt[j],tt[j]=0;
				if(vis[n]){
					cout<<tim;RE 0;
				}
			}
		}
	}
	int tim=p[m].F,cnt=n+1;
	FOR(j,1,n)vis[j]=now.a[1][j];
//	cout<<tim<<' ';
	while(cnt--){
		tim++;
		FOR(j,1,n)FOR(k,1,n)if(to[j][k]&&vis[j])tt[k]=1;
		FOR(j,1,n)vis[j]=tt[j],tt[j]=0;
		if(vis[n]){
			cout<<tim;RE 0;
		}
	}
	cout<<"Impossible";
	RE 0;
}