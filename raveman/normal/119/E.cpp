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

int n,m;
int x[1111],y[1111],z[1111];

pdd p[1111];

const double eps = 1e-6;

void parse(int A,int B,int C,double &x,double &y,double &z){
	double t = (A*x+B*y+C*z)/(A*A+B*B+C*C);
	x -= A*t;
	y -= B*t;
	z -= C*t;
}

pdd project(int A,int B,int C,double x,double y,double z){
	parse(A,B,C,x,y,z);

	if(B==0 && C==0) return pdd(y,z);

	
	double xx = 1,yy=0,zz=0;
	if(B) yy=(-A)/double(B);
	else if(C) zz = (-A)/double(C);

	double d1 = sqrt(x*x+y*y+z*z+0.);
	if(d1<eps) return pdd(0.,0.);
	double d2 = sqrt(B*B+C*C+0.);
	double d3 = sqrt(x*x+(y-C)*(y-C)+(z+B)*(z+B));
	double a = (d1*d1+d2*d2-d3*d3)/(2*d1*d2);
	a = acos(a);
	if(x<0) a=-a;
	return pdd(d1*cos(a),d1*sin(a));
}

bool good(int A,int B,int C,double r){
	//random_shuffle(p,p+n);
	double X = p[0].first;
	double Y = p[0].second;
	FOR(i,1,n){
		if((X-p[i].first)*(X-p[i].first)+(Y-p[i].second)*(Y-p[i].second)<=r*r+eps) continue;
		bool found = 0;
		REP(j,i){
			double d = (p[j].first-p[i].first)*(p[j].first-p[i].first)+(p[j].second-p[i].second)*(p[j].second-p[i].second);
			if(d>4*r*r) return 0;

			double dx = p[j].first - p[i].first, dy = p[j].second - p[i].second;
			swap(dx,dy); dx=-dx;

			double z = sqrt((r*r - d / 4)/(dx*dx+dy*dy));
			dx *= z;
			dy *= z;

			REP(up,2){
				X = (p[i].first+p[j].first)/2 + (up?-1:1)*dx, Y = (p[i].second+p[j].second)/2 + (up?-1:1)*dy;
				bool g = 1;
				REP(k,i+1) if((X-p[k].first)*(X-p[k].first)+(Y-p[k].second)*(Y-p[k].second)>r*r+eps){g=0;break;}
				if(g){found=1;break;}
			}
			if(found) break;
		}
		if(!found) return 0;
	}
	return 1;
}

double solve(int A,int B,int C){
	REP(i,n) p[i] = project(A,B,C,x[i],y[i],z[i]);//, cout<<p[i].first<<' '<<p[i].second<<endl;
	random_shuffle(p,p+n);
	double a = 0;
	double b = 1e5;
	REP(_it,40){
		double s = (a+b)/2;
		if(good(A,B,C,s)) b = s;
		else a = s;
		//cout<<s<<' '<<good(A,B,C,s)<<' '<<a<<' '<<b<<endl;
	}
	return b;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n) scanf("%d %d %d",x+i,y+i,z+i);
	REP(i,m){
		int A,B,C;
		scanf("%d %d %d",&A,&B,&C);
		printf("%.10lf\n",solve(A,B,C));
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}