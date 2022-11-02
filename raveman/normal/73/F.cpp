#pragma comment(linker, "/STACK:60777216")  

#include <algorithm>
#include <iostream>
#include <complex>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <ctime>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define sz(a)                   int(a.size())
#define all(a)                  (a).begin(), (a).end()
#define CL(a, b)                memset(a, b, sizeof a) 
#define FOR(i, a, b)			for (int i(a); i < (b); ++i)
#define REP(i, n)               FOR(i, 0, n)
#define UN(a)                   sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb                      push_back
#define SORT(a)                 sort(all(a))

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

double xa,ya,xb,yb;
int n;
double x[11111],y[11111],a[11111],w[11111];
int k;

const double pi = acos(-1.);

double go(double a,double w){
	double v = 0;
	int num = 100;
	REP(i,num+1){
		
		double x = xa + (xb-xa)*i/double(num);
		double y = ya + (yb-ya)*i/double(num);
		double q = atan2(y,x) - a;

		if(q>2*pi) q-=2*pi;
		while(q<0) q+=2*pi;
		if(q>2*pi-q) q = 2*pi - q;

		double T = (w < 1e-5 ? (i==0 ? 0 : 1e10) : q/w);

		v = max(v,hypot(x-xa,y-ya)/T);
	}


	return v;
}

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif

	cin>>xa>>ya>>xb>>yb>>n;
	REP(i,n) scanf("%lf %lf %lf %lf",x+i,y+i,a+i,w+i);
	cin>>k;

	vector<double> v;
	REP(i,n){
		xa-=x[i],ya-=y[i],xb-=x[i],yb-=y[i];
		v.pb(go(a[i],w[i]));
		xa+=x[i],ya+=y[i],xb+=x[i],yb+=y[i];
	}
	SORT(v);
	reverse(v.begin(),v.end());
	if(k>=v.size()) puts("0.0000");
	else printf("%.4lf\n",v[k]);
	return 0;
}