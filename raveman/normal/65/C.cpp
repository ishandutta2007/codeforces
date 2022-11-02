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

#define sz(a)			int(a.size())
#define all(a)			(a).begin(), (a).end()
#define CL(a, b)		memset(a, b, sizeof a) 
#define FOR(i, a, b)	for (int i(a); i < (b); ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(a)			sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb				push_back
#define SORT(a)			sort(all(a))

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n;
int x[11111];
int y[11111];
int z[11111];

const double eps = 1e-12;

double hypot(double a,double b,double c){
	return sqrt(0. + a*a+b*b+c*c);
}

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif

	cin>>n;
	n++;
	REP(i,n) scanf("%d %d %d",x+i,y+i,z+i);

	int vp,vs;
	cin>>vp>>vs;
	int X,Y,Z;
	cin>>X>>Y>>Z;
	REP(i,n) x[i]-=X,y[i]-=Y,z[i]-=Z;
	double t = 0;
	REP(i,n-1){
		double te = t + hypot(x[i+1]-x[i],y[i+1]-y[i],z[i+1]-z[i])/vs;

		double p = hypot(x[i+1],y[i+1],z[i+1]) / vp;
		if(p - eps <= te){
			puts("YES");
			double a = 0, b = 1;
			REP(j,200){
				double s = (a+b)/2;


				double p = hypot(x[i] + (x[i+1]-x[i])*s,y[i]+(y[i+1]-y[i])*s,z[i]+(z[i+1]-z[i])*s) / vp;
				double T = t + s * hypot(x[i+1]-x[i],y[i+1]-y[i],z[i+1]-z[i])/vs;

				if(p-eps <= T) b = s;
				else a = s;
			}
			double s = (a+b)/2;
			double T = t + s * hypot(x[i+1]-x[i],y[i+1]-y[i],z[i+1]-z[i])/vs;

			printf("%.9lf\n",T);
			printf("%.9lf %.9lf %.9lf\n",X+x[i]+s*(x[i+1]-x[i]),Y+y[i]+s*(y[i+1]-y[i]),Z+z[i]+s*(z[i+1]-z[i]));
			return 0;

		}

		t = te;
	}
	puts("NO");

	return 0;
}