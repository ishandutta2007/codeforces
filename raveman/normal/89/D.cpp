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

int ax,ay,az;
int vx,vy,vz;
int R;
int n;
int x,y,z,r,m;
int px;
int py;
int pz;
double t = 1e100;

double solve(ll x,ll y,ll z,ll r){
	double A = vx * vx + vy * vy + vz * vz;
	double B = - 2 * vx * x - 2 * vy * y - 2 * vz * z;
	double C = x * x + y * y + z * z - (R+r)*(R+r);

	double D = B*B - 4 * A * C;
	if( D < 0) return 1e100;
	D = sqrt(D);

	double t1 = (- B - D)/2/A;
	double t2 = (- B + D)/2/A;
	double res = 1e100;
	if(t1>=0) res = min(res,t1);
	if(t2>=0) res = min(res,t2);
	return res;
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	cin>>ax>>ay>>az>>vx>>vy>>vz>>R;
	cin>>n;
	REP(i,n){
		cin>>x>>y>>z>>r>>m;
		x -= ax;
		y -= ay;
		z -= az;
		t = min(t, solve(x,y,z,r));
		REP(j,m){
			cin>>px>>py>>pz;
			t = min(t, solve(x + px, y + py, z + pz, 0));
		}
	}
	if(t>1e50) puts("-1");
	else printf("%.10lf\n",t);
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}