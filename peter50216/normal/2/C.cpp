#include <stdio.h>
#include <math.h>

#define EPS 1E-7

inline int SG(long double x) {
    if(x>-EPS && x<EPS) return 0;
    return x>0?1:-1;
}

class PT{
    public:
	long double x,y,r;
	PT(){}
	PT(long double _x,long double _y) {
	    x = _x; y = _y;
	}
	bool input() {
	    double xx,yy,rr;
	    if(scanf("%lf %lf %lf",&xx,&yy,&rr)!=3)return 0;
	    x=xx;y=yy;r=rr;return 1;
	}
	PT operator+(const PT& p) const {
	    return PT(x+p.x,y+p.y);
	}
	PT operator-(const PT& p) const {
	    return PT(x-p.x,y-p.y);
	}
	PT operator*(const double c) const {
	    return PT(x*c,y*c);
	}
	PT operator/(const double c) const {
	    return PT(x/c,y/c);
	}
	long double operator*(const PT& p) const {
	    return x*p.x+y*p.y;
	}
	long double operator^(const PT& p) const {
	    return x*p.y-y*p.x;
	}
	long double len() {
	    return sqrt(x*x+y*y);
	}
	void prt() {
	    printf("%.5f %.5f\n",(double)x+1e-5,(double)y+1e-5);
	}
};

inline long double tri(PT p1,PT p2,PT p3) {
    return p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-(p1.y*p2.x+p2.y*p3.x+p3.y*p1.x);
}

inline PT cir(PT p1,PT p2) {
    long double a,b;
    PT p,q,o;
    a = p2.r;
    b = p1.r;
    p = (p1*a+p2*b)/(a+b);
    q = (p1*a-p2*b)/(a-b);
    o = (p+q)/2;
    o.r = (p-o).len();
    return o;
}

inline PT triO(PT p1,PT p2,PT p3) {
    PT p,q,o,pv,qv;
    long double ta,tb;
    p = (p1+p2)/2;
    q = (p1+p3)/2;
    pv = p2-p1;
    pv = PT(pv.y,-pv.x)+p;
    qv = p3-p1;
    qv = PT(qv.y,-qv.x)+q;
    ta = tri(p,pv,q);
    tb = tri(p,pv,qv);
    o = (q*tb-qv*ta)/(tb-ta);
    return o;
}

inline bool sect(PT p1,PT p2,PT &q1,PT &q2) {
    if(p1.r<p2.r) return sect(p2,p1,q1,q2);
    long double a,b,c,d;
    PT p,q;
    a = p1.r;
    b = p2.r;
    c = (p1-p2).len();
    if(a+b<c || a-b>c) return false;
    d = (a*a+c*c-b*b)/(2*c);
    p = p1+(p2-p1)*(d/c);
    q = p2-p1;
    q = PT(q.y,-q.x)*sqrt(a*a-d*d)/q.len();
    q1 = p+q;
    q2 = p-q;
    return true;
}

int main() {
    PT p1,p2,p3,o12,o23,o13,s1,s2,s,tmp,p,q;
    long double md,d;
    while(p1.input()) {
	p2.input();
	p3.input();
	if(SG(p1.r-p2.r)==0) {
	    tmp = p3; p3 = p1; p1 = tmp;
	}
	if(SG(p1.r-p3.r)==0) {
	    tmp = p2; p2 = p1; p1 = tmp;
	}
	if(SG(p1.r-p2.r)==0) {
	    s = triO(p1,p2,p3);
	    s.prt();
	    continue;
	}
	md = 1E11;
	o12 = cir(p1,p2);
	o13 = cir(p1,p3);
	if(!sect(o12,o13,s1,s2)) goto out;
	md = (s1-p1).len();
	s = s1;
	d = (s2-p1).len();
	if(d<md) {
	    md = d;
	    s = s2;
	}
out:
	if(md<1E10) {
	    s.prt();
	    //printf("%.5f %.5f %.5f\n",p1.r/(p1-s).len(),p2.r/(p2-s).len(),p3.r/(p3-s).len());
	}
    }
    return 0;
}