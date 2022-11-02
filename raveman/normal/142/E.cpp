#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

typedef long double ld;
const ld pi = acosl(-1.);
const ld eps = 1e-17;

int r,h;

ld getAngle(ld x,ld y, ld z){
	ld H = h - z;
	if(H<eps) return 0;
	ld R = r * H / h;
	ld X = 0;
	ld Y = R;
	ld d = sqrtl((x-X)*(x-X)+(y-Y)*(y-Y));
	ld a = asinl(d/2/R)*2;
	ld l = a * R / sqrtl(R*R+H*H);
	if(x>0) l=-l;
	return l;
}

ld conDist(ld z,ld Z,ld a){
	ld r1 = sqrtl(h*h+r*r+0.)/h*(h-z);
	ld r2 = sqrtl(h*h+r*r+0.)/h*(h-Z);
	ld x = r1;
	ld y = 0;
	ld X = cosl(a)*r2;
	ld Y = sinl(a)*r2;
	return sqrtl((x-X)*(x-X)+(y-Y)*(y-Y));
}

ld getOnConus(ld x,ld y,ld z,ld X, ld Y,ld Z){
	ld a1 = getAngle(x,y,z);
	ld a2 = getAngle(X,Y,Z);
	ld a = fabsl(a2-a1);
	ld A = r / sqrtl(h*h+r*r+0.) * 2 * pi; 
	return min(conDist(z,Z,a),conDist(z,Z,A-a));
}

ld getOnConus(ld x,ld y,ld z,ld X, ld Y){
	if(z>eps) return getOnConus(x,y,z,X,Y,0);
	return sqrtl((x-X)*(x-X)+(y-Y)*(y-Y));
}

ld getD(ld x,ld y,ld z,ld X, ld Y,ld Z,ld XX,ld YY,ld XXX,ld YYY){
	ld res = sqrtl((XX-XXX)*(XX-XXX)+(YY-YYY)*(YY-YYY));
	res += getOnConus(x,y,z,XX,YY);
	res += getOnConus(X,Y,Z,XXX,YYY);
	return res;
}

ld getD(ld x,ld y,ld z,ld X, ld Y,ld Z,ld XX,ld YY){
	ld res = 1e100;
	REP(i,6){
		ld a = 2*pi/3*i;
		ld b = a + pi;
		REP(j,40){
			ld s1 = (a*2+b)/3;
			ld s2 = (a+2*b)/3;
			ld d1 = getD(x,y,z,X,Y,Z,XX,YY,cosl(s1)*r,sinl(s1)*r);
			ld d2 = getD(x,y,z,X,Y,Z,XX,YY,cosl(s2)*r,sinl(s2)*r);
			res = min(res,min(d1,d2));
			if(d1<d2) b = s2;
			else a = s1;
		}
	}
	return res;
}

ld go(ld x,ld y,ld z,ld X, ld Y,ld Z){
	ld res = getOnConus(x,y,z,X,Y,Z);
	if(z<eps || Z<eps) res = 1e100;
	REP(i,6){
		ld a = 2*pi/3*i;
		ld b = a + pi;
		REP(j,40){
			ld s1 = (a*2+b)/3;
			ld s2 = (a+2*b)/3;
			ld d1 = getD(x,y,z,X,Y,Z,cosl(s1)*r,sinl(s1)*r);
			ld d2 = getD(x,y,z,X,Y,Z,cosl(s2)*r,sinl(s2)*r);
			res = min(res,min(d1,d2));
			if(d1<d2) b = s2;
			else a = s1;
		}
	}
	return res;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif

	cin>>r>>h;
	long double x,y,z,X,Y,Z;
	cin>>x>>y>>z>>X>>Y>>Z;
	if(z<eps && Z<eps)
		printf("%.10lf\n",(double)sqrt((x-X)*(x-X)+(y-Y)*(y-Y)));
	else printf("%.10lf\n",(double)go(x,y,z,X,Y,Z));
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}