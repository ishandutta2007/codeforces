#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <cassert>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

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

double xp,yp,vp;
double x,y,r,v;
double R;

const double pi = acos(-1.);
const double eps = 1e-8;

bool inter(double x,double y,double X,double Y,double r){
	double dx = X - x;
	double dy = Y - y;
	if(hypot(dx,dy)<eps) 
		return 0;
	double A = dx * dx + dy * dy;
	double B = 2 * x * dx + 2 * y * dy;
	double C = x * x + y * y - r * r;
	double D = B * B - 4 * A * C;
	if(D<=0) return 0;
	D = sqrt(D);
	double t1 = (-B-D)/(2*A);
	double t2 = (-B+D)/(2*A);
	if(t1>=eps && t1<=1-eps) return 1;
	if(t2>=eps && t2<=1-eps) return 1;
	return 0;
}

vector<pdd> go(double x,double y,double r){
	double d = hypot(x,y);
	vector<pdd> res;
	double a = asin(r/d);

	complex<double> V(-x,-y);
	V /= d;
	V *= sqrt(d*d-r*r);

	V *= polar(1., a);
	res.pb(pdd(x+V.real(),y+V.imag()));
	V *= polar(1., -2*a);
	res.pb(pdd(x+V.real(),y+V.imag()));
	
	return res;
}

bool good(double t){
	double angle = atan2(yp,xp);
	angle += t / (2 * pi * R / vp) * 2 * pi;
	double X = R * cos(angle);
	double Y = R * sin(angle);
	
	double len = 0;

	if(inter(x,y,X,Y,r)){
		vector<pdd> v1 = go(x,y,r);
		vector<pdd> v2 = go(X,Y,r);
		len = 1e100;
		REP(i,v1.size()) REP(j,v2.size()){
			double vv = 0;
			vv += hypot(v1[i].first - x, v1[i].second - y);
			vv += hypot(v2[j].first - X, v2[j].second - Y);
			double a = atan2(v1[i].second, v1[i].first);
			a -= atan2(v2[j].second, v2[j].first);
			a = fabs(a);
			vv += r*min(a,2*pi-a);
			len = min(len, vv);
		}
	//	cout<<len<<endl;
	}else len = hypot(x-X,y-Y);

	return len <= v * t;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>xp>>yp>>vp;
	cin>>x>>y>>v>>r;
	R = hypot(xp,yp);

	double a = 0;
	double b = 1e10;
	REP(i,100){
		double t = (a+b)/2;
		if(good(t)) b = t;
		else a = t;
	}
	printf("%.10lf\n",b);
	
#ifdef LocalHost
	cerr<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}