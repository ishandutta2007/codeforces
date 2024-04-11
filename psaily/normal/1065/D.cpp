#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
//head

const int N=11;
const int M=105;
int n,m;
int a[M][M],pos[M];

pii f[3][M][M];// f[id][gl][p]

int gps(int x,int y) {
	if (x<0||x>=n||y<0||y>=n) return -1;
	return x*n+y;
}

struct node {
	int id,gl,p;
	pii v;
	node(){}
	node(int id,int gl,int p,pii v):id(id),gl(gl),p(p),v(v){}
};
int l,r;
node que[5000005];

int main() {
	cin>>n; m=n*n;
	rep(i,0,n) rep(j,0,n) cin>>a[i][j],pos[a[i][j]]=gps(i,j);
	rep(i,0,3) rep(j,0,m+1) rep(k,0,m+1) f[i][j][k]=mp(inf,inf);
	l=1,r=0;
	rep(i,0,3) que[++r]=node(i,2,pos[1],mp(0,0));
	pii ans=mp(inf,inf);
	while (l<=r) {
		node e=que[l++];
		if (e.v>=f[e.id][e.gl][e.p]) continue;
		// debug(r);
		f[e.id][e.gl][e.p]=e.v;
		// bug(e.id),bug(e.gl),bug(e.p),debug(e.v.fi);
		
		int nx=e.p/n,ny=e.p%n;
		
		if (e.p==pos[e.gl]) {
			if (e.gl==n*n) {ans=min(ans,e.v); continue;}
			que[++r]=node(e.id,e.gl+1,e.p,e.v);
			continue;
		}
		
		if (e.id==0) {
			// puts("in");
			rep(i,0,n) if (i!=ny) {
				int np=gps(nx,i);
				que[++r]=node(e.id,e.gl,np,mp(e.v.fi+1,e.v.se));
			}
			rep(i,0,n) if (i!=nx) {
				int np=gps(i,ny);
				que[++r]=node(e.id,e.gl,np,mp(e.v.fi+1,e.v.se));
			}
			// puts("out");
		}else if (e.id==1) {
			rep(i,-n,n+1) if (i) {
				int np=gps(nx+i,ny+i);
				if (~np) que[++r]=node(e.id,e.gl,np,mp(e.v.fi+1,e.v.se));
			}
			rep(i,-n,n+1) if (i) {
				int np=gps(nx-i,ny+i);
				if (~np) que[++r]=node(e.id,e.gl,np,mp(e.v.fi+1,e.v.se));
			}
		}else {
			rep(i,0,2) rep(j,0,2) {
				int op1=i?-1:1,op2=j?-1:1;
				int np=gps(nx+2*op1,ny+1*op2);
				if (~np) que[++r]=node(e.id,e.gl,np,mp(e.v.fi+1,e.v.se));
				np=gps(nx+1*op1,ny+2*op2);
				if (~np) que[++r]=node(e.id,e.gl,np,mp(e.v.fi+1,e.v.se));
			}
		}
		
		rep(i,0,3) if (i!=e.id) que[++r]=node(i,e.gl,e.p,mp(e.v.fi+1,e.v.se+1));
	}
	printf("%d %d\n",ans.fi,ans.se);
	
	return 0;	
}