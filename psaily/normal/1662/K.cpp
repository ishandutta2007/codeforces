#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl 
mt19937 mrand(time(0)); 

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7;
const ll inf=1<<30;
// head
const int N=1e6+5;
int n,m;
db ans;

namespace Geometry {
	const db eps=(db)1e-8;
	const db pi=(db)acos(-1.0);
	int sgn(const db &x){return x<-eps?-1:x>eps;}
	#define vect point
	struct point {
		db x,y;
		point(){}
		point(db _x,db _y):x(_x),y(_y){}
		point operator +(point s){return point(x+s.x,y+s.y);}
		point operator -(point s){return point(x-s.x,y-s.y);}
		point operator *(db k){return point(x*k,y*k);}
		point operator /(db k){return point(x/k,y/k);}
		db operator *(point p){return x*p.x+y*p.y;}// dot
    	db operator ^(point p){return x*p.y-y*p.x;}// det
    	// compare
		bool operator <(point s) { //sort by x first,then y
			return !sgn(x-s.x)?sgn(y-s.y)<0:sgn(x-s.x)<0;
		}
		bool operator > (point s){return s<*this;}
		bool operator ==(point s){return !sgn(x-s.x)&&!sgn(y-s.y);}
		bool operator <=(point s){return !(*this>s);}
		bool operator >=(point s){return !(*this<s);}
		bool operator !=(point s){return !(*this==s);}
		
    	db getl(){return x*x+y*y;}
    	db len(){return sqrt(x*x+y*y);}
		db _tan(){return y/x;}
		db angle()const{return atan2(y,x);}//get_angle 
		db angle(point t) {
			db r=atan2((*this)^t,(*this)*t);
			return r;
			// return r<0?r+2*pi:r;
		}
		
		point unit(){return *this/len();}
		point unit_len(db d){return unit()*d;}
		point normal(){return point(-y,x);}//
		point symmetry(point s){return s+s-*this;}//s,s
		point rotate(db a){return point(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));}//a
		
    	db dot(point a,point b){return (a-*this)*(b-*this);}//
    	db det(point a,point b){return (a-*this)^(b-*this);}//
	};
	db norm(db x) {return x*x;}
	db dist(point a,point b) {return (a-b).len();}	
	db angle(vect a,vect b) {return a.angle(b);} // ab(-pi,pi)
	db angle(point x,point s,point t) {
		vect xs=s-x,xt=t-x;
		return fabs(xs.angle(xt));
	}
	void print(point s) {
		bug(s.x),debug(s.y);
	}
	bool in_line(point a,point b,point s) {//
		return !sgn((s-a)^(s-b));
	}
}
using namespace Geometry;

point a[N],b[N];
db gao(point s,point ss,point tt) {// triangle(s,ss,tt)
	db res=min({dist(s,ss)+dist(s,tt),dist(ss,s)+dist(ss,tt),dist(tt,s)+dist(tt,ss)});
	if (!in_line(s,ss,tt)) {
		db t=max({angle(s,ss,tt),angle(ss,s,tt),angle(tt,s,ss)});
		if (t<pi*2/3) {
			db ag=angle(s,ss,tt); ag+=pi/3;
			db u=dist(s,ss),v=dist(s,tt);
			res=min(res,sqrt(norm(u)+norm(v)-2*u*v*cos(ag)));
		}
	}
	return res;
}

// namespace simulate_anneal {// 
// 	int rnd(int x) {return mrand()%x;}
// 	db rand(db l,db r) {// generate [l,r]
// 		return (db)rnd(RAND_MAX)/RAND_MAX*(r-l)+l;
// 	}
// 	db calc(point x) {
// 		db ret=0;
// 		rep(j,0,3) rep(k,j+1,3) {
// 			ret=max(ret,gao(x,b[j],b[k]));
// 		}
// 		ans=min(ans,ret);
// 		return ret;
// 	}
// 	void solve() {
// 		db xmx=-1e18,xmn=1e18,ymx=-1e18,ymn=1e18;
// 		rep(i,0,3) {
// 			xmx=max(xmx,a[i].x);
// 			ymx=max(ymx,a[i].y);
// 			xmn=min(xmn,a[i].x);
// 			ymn=min(ymn,a[i].y);
// 		}
// 		point cur(rand(xmn,xmx),rand(ymn,ymx));
// 		// point cur(rand(-1e4,1e4),rand(-1e4,1e4));
// 		for (db T=1e4;T>1e-5;T*=0.92) {
// 			point np(rand(cur.x-T,cur.y+T),rand(cur.x-T,cur.y+T));
// 			db dt=calc(np)-calc(cur);
// 			if (exp(-dt/T)>rand(0,1)) cur=np;
// 		}
// 	}
// }
// using namespace simulate_anneal;

// bool check(db mid) {
// 	ans=1e18;
// 	rep(_,0,40) solve();
// 	return ans<=mid;
// }	


int main() {
	rep(i,0,3) scanf("%lf%lf",&b[i].x,&b[i].y);
	// db l=0,r=1e9;
	// rep(_,0,50) {
	// 	db mid=(l+r)/2.0;
	// 	if (check(mid)) r=mid;
	// 	else l=mid;
	// }
	
	db t=1,ans=1e9;
	db f[3];
	point pos=b[0];
	while (t>eps) {
		f[0]=gao(pos,b[0],b[1]);	
		f[1]=gao(pos,b[1],b[2]);
		f[2]=gao(pos,b[0],b[2]);
		ans=min(ans,max({f[0],f[1],f[2]}));
		if (f[0]<=f[1]&&f[0]<=f[2]) {
			pos=pos+(b[2]-pos)*t;
		}else if (f[1]<=f[0]&&f[1]<=f[2]) {
			pos=pos+(b[0]-pos)*t;
		}else {
			pos=pos+(b[1]-pos)*t;
		}
		t*=0.9;
	}
	
	printf("%.10lf\n",ans);
	return 0;	
}