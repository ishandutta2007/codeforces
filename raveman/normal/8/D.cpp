#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int t1,t2,x[3],y[3];
double r[3];

bool good(double X,double Y){
	if(!(X>0 || X < 1)) return 0;
	REP(i,3){
		double d = hypot(X-x[i],Y-y[i]);
		if(d>r[i]+1e-11) return 0;
	}
	return 1;
}

bool good(double R){
	r[0] = R;
	r[1] = hypot(x[1], y[1]) + t1 - R;
	r[2] = hypot(x[2], y[2]) + t2 - R;
	if(r[1] < 0 || r[2]<0) return 0;
	REP(i,3) if(good(x[i],y[i])) return 1;
	REP(i,3) REP(j,i){
		double d = hypot(x[i] - x[j], y[i] - y[j]);
		if(d > r[i] + r[j]) continue;

		double a = acos(min(1.,(d*d + r[i] * r[i] - r[j]*r[j]) / 2 / d / r[i]));

		complex<double> v(x[j] - x[i], y[j] - y[i]);
		v /= abs(v);
		v *= r[i];

		v *= polar(1., -a);
		if(good(x[i] + v.real(), y[i] + v.imag())) return 1;
		v *= polar(1., 2* a);
		if(good(x[i] + v.real(), y[i] + v.imag())) return 1;
	}
	return 0;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif
	cin>>t2>>t1;
	REP(i,3) cin>>x[i]>>y[i];
	FOR(i,1,3) x[i] -= x[0], y[i] -= y[0];
	x[0] = y[0] = 0;

	double a = 0, b = 1000,best=0;
	REP(i,100){
		double s = (a+b)/2;
		if(good(s)) a = s, best = s;
		else b = s;
	}

	//cout<<good(6)<<endl;
	if(hypot(x[2], y[2]) + hypot(x[1] - x[2], y[1] - y[2]) <= hypot(x[1],y[1]) + t1 + 1e-9)
		best = min(hypot(x[2], y[2]) + hypot(x[1] - x[2], y[1] - y[2]) + t2, hypot(x[1],y[1]) + t1);
	printf("%.10lf\n",best);

	return 0;
}