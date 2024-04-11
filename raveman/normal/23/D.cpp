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

pii p[4];
int a[2][3];

const double eps = 1e-9;

double dist(pdd &x,pdd &y){return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second);}

bool good(vector<pdd> &v){
	if(fabs(dist(v[0],v[1])-dist(v[1],v[2]))>eps) return 0;
	if(fabs(dist(v[1],v[2])-dist(v[2],v[3]))>eps) return 0;
	vector<double> s;
	REP(i,4){
		int i1 = i;
		int i2 = (i+1)%4;
		int i3 = (i+2)%4;
		double sq = (v[i2].first -  v[i1].first)*(v[i3].second-v[i1].second)-(v[i3].first-v[i1].first)*(v[i2].second-v[i1].second);
		s.pb(sq);
	}
	SORT(s);
	return s.back() < -eps;
}

int det(int a,int b,int c,int d){return a*d-b*c;}

void go(double &x,double &y,int t){
	x = 2 * p[t].first - x;
	y = 2 * p[t].second - y;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		REP(i,3) cin>>p[i].first>>p[i].second;
		sort(p,p+3);

		bool f = 0;

		do{
			int x0 = (3 * p[1].first - p[0].first );
			int y0 = (3 * p[1].second - p[0].second);
			int dx = p[1].first - p[0].first;
			int dy = p[1].second - p[0].second;
			swap(dx,dy); dx = -dx;

			int x1 = (p[1].first  + p[2].first);
			int y1 = (p[1].second + p[2].second);
			int dx2 = p[2].first - p[1].first;
			int dy2 = p[2].second - p[1].second;
			swap(dx2,dy2); dx2=-dx2;

			a[0][0] = dx; a[0][1] = -dx2; a[0][2] = x1 - x0;
			a[1][0] = dy; a[1][1] = -dy2; a[1][2] = y1 - y0;

			int d = det(a[0][0],a[0][1],a[1][0],a[1][1]);

			if(d){
				int c = det(a[0][2], a[0][1], a[1][2], a[1][1]);

				double x = x0 / 2. + dx * c / 2. / d;
				double y = y0 / 2. + dy * c / 2. / d;

				go(x,y,1);
				go(x,y,0);

				vector<pdd> v;
				v.pb(pdd(x,y));
				go(x,y,0);
				v.pb(pdd(x,y));
				go(x,y,1);
				v.pb(pdd(x,y));
				go(x,y,2);
				v.pb(pdd(x,y));
				if(good(v)){
					f=1;
					puts("YES");
					REP(i,4){
						if(i) printf(" ");
						printf("%.9lf %.9lf",v[i].first,v[i].second);
					}
					puts("");

					break;
				}
			}

		}while(next_permutation(p,p+3));

		if(!f) puts("NO\n");
	}

	return 0;
}