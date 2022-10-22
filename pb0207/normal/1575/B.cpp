#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)

typedef double db;
typedef long long ll;

const int N=2e5+50;
const db eps=1e-6;
const db pi=acos(-1);

int sgn(db x) {
	return x<-eps?-1:x>eps;
}
struct Point {
	db x,y;
	db Len2() const{
		return x*x+y*y;
	}
	db Len() const{
		return sqrt(x*x+y*y);
	}
} a[N];
int n,K;
struct node {
	db x;
	int v;
	bool operator <(const node &s) const{
		return x<s.x;
	}
} b[N*4];
int m=0;
void add(db l,db r) {
	if(sgn(l-(-pi))<0) {
		add(l+pi*2,pi);
		add(-pi,r);
	} else if(sgn(r-pi)>0) {
		add(l,pi);
		add(-pi,r-pi*2);
	} else {
		b[++m]=(node){l,1};
		b[++m]=(node){r+eps,-1};
	}
}
bool check(db r) {
	m=0;
	FOR(i,1,n) {
		if(sgn(4*r*r-a[i].Len2())<eps) {
			continue;	
		}
		db p=atan2(a[i].y,a[i].x);
		db delt=acos(a[i].Len()/2/r);
		add(p-delt,p+delt);
	}
	sort(b+1,b+m+1);
	int t=0;
	if(t>=K) return 1;
	FOR(i,1,m) {
		t+=b[i].v;
		if(t>=K) return 1;
	}
	return 0;
}
int main() {
	scanf("%d%d",&n,&K);
	int c=0;
	FOR(i,1,n) {
		++c;
		scanf("%lf%lf",&a[c].x,&a[c].y);
		if(sgn(a[c].x)==0 && sgn(a[c].y)==0) {
			--c;
			--K;
		}
	}
	n=c;
	db L=0,R=5e5;
	while(R-L>eps) {
		db mid=(L+R)/2;
		if(check(mid)) R=mid;
		else L=mid;
	}
	printf("%lf\n",L);
	return 0;
}