#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
int p[MAXN],q[MAXN],lim[MAXN];
int n;
P a[MAXN];
std::vector<int> Sx,Sy;
int X[MAXN],Y[MAXN];
int sm[MAXN<<5],lc[MAXN<<5],rc[MAXN<<5],root[MAXN],tot;

inline void update(int prev,int &v,int l,int r,int p){
	v = ++tot;sm[v] = sm[prev]+1;lc[v] = lc[prev];rc[v] = rc[prev];
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(p <= mid) update(lc[prev],lc[v],l,mid,p);
	else update(rc[prev],rc[v],mid+1,r,p);
}

inline int query(int x,int y,int l,int r,int L,int R){
	if(!x && !y) return 0;
	// DEBUG(l);DEBUG(r);DEBUG(L);DEBUG(R);
	// DEBUG(sm[y]-sm[x]);
	if(l == L && r == R){
		// DEBUG(sm[y]-sm[x]);
		return sm[y]-sm[x];
	}
	int mid = (l + r) >> 1;
	if(R <= mid) return query(lc[x],lc[y],l,mid,L,R);
	if(L > mid) return query(rc[x],rc[y],mid+1,r,L,R);
	return query(lc[x],lc[y],l,mid,L,mid)+query(rc[x],rc[y],mid+1,r,mid+1,R);
}

double x[2],y[2];
int rt[MAXN],xmax,ymax;

inline int calc(int x0,int y0,int x1,int y1){
	return query(rt[x0-1],rt[x1],1,n,y0,y1);
}

inline bool chk(){
	int x0,x1,y0,y1;
	int ps1 = p[1]+p[2]+p[3],ps2 = p[1]+p[2]+p[3]+p[4]+p[5]+p[6],ps3 = p[1]+p[4]+p[7],ps4 = p[1]+p[4]+p[7]+p[2]+p[5]+p[8];
	x0 = X[ps1];x1 = X[ps2];y0 = Y[ps3];y1 = Y[ps4];
	if(X[ps1] == X[ps1+1] || X[ps2] == X[ps2+1] || Y[ps3] == Y[ps3+1] || Y[ps4] == Y[ps4]+1) return false;
	// DEBUG(calc(1,3,1,3));
	// exit(0);
	if(p[1] != calc(1,1,x0,y0) || p[2] != calc(1,y0+1,x0,y1) || p[3] != calc(1,y1+1,x0,ymax)) return false;
	if(p[4] != calc(x0+1,1,x1,y0) || p[5] != calc(x0+1,y0+1,x1,y1) || p[6] != calc(x0+1,y1+1,x1,ymax)) return false;
	if(p[7] != calc(x1+1,1,xmax,y0) || p[8] != calc(x1+1,y0+1,xmax,y1) || p[9] != calc(x1+1,y1+1,xmax,ymax)) return false;
	x[0] = 1.0*(Sx[X[ps1]-1]+Sx[X[ps1+1]-1])/2.0;x[1] = 1.0*(Sx[X[ps2]-1]+Sx[X[ps2+1]-1])/2.0;
	y[0] = 1.0*(Sy[Y[ps3]-1]+Sy[Y[ps3+1]-1])/2.0;y[1] = 1.0*(Sy[Y[ps4]-1]+Sy[Y[ps4+1]-1])/2.0;
	return true;
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
	FOR(i,1,n) Sx.pb(a[i].fi),Sy.pb(a[i].se);
	std::sort(all(Sx));Sx.erase(std::unique(all(Sx)),Sx.end());
	std::sort(all(Sy));Sy.erase(std::unique(all(Sy)),Sy.end());
	FOR(i,1,n) a[i].fi = std::lower_bound(all(Sx),a[i].fi)-Sx.begin()+1,
		a[i].se = std::lower_bound(all(Sy),a[i].se)-Sy.begin()+1;
	FOR(i,1,n) X[i] = a[i].fi,Y[i] = a[i].se;
	std::sort(X+1,X+n+1);std::sort(Y+1,Y+n+1);
	std::sort(a+1,a+n+1);xmax = X[n];ymax = Y[n];
	FOR(i,1,n) update(root[i-1],root[i],1,n,a[i].se),rt[a[i].fi] = root[i];
	FOR(i,1,9) scanf("%d",lim+i),q[i] = i;
	do{
		FOR(i,1,9) p[i] = lim[q[i]];
		if(chk()){
			printf("%.10f %.10f\n%.10f %.10f\n",x[0],x[1],y[0],y[1]);
			return 0;
		}
	}while(std::next_permutation(q+1,q+10));
	puts("-1");
	return 0;
}