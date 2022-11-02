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

int n;
vector<pii> v[111111];
int x[111111];
int y[111111];
double s[111111];
double e[111111];

bool	u_sum_start[111111][2];
double    sum_start[111111][2];

double getSumStart(int edge, int ver){
	int type = (x[edge] == ver? 0 : 1);
	if(u_sum_start[edge][type]) return sum_start[edge][type];
	if(u_sum_start[edge][1-type]) return 1-sum_start[edge][1-type];
	double res = s[ver];
	REP(i,v[ver].size()) if(v[ver][i].second!=edge)
		res += getSumStart(v[ver][i].second,v[ver][i].first);
	return u_sum_start[edge][type]=1,sum_start[edge][type]=res;
}


bool	u_sum_end[111111][2];
double    sum_end[111111][2];

double getSumEnd(int edge, int ver){
	int type = (x[edge] == ver? 0 : 1);
	if(u_sum_end[edge][type]) return sum_end[edge][type];
	if(u_sum_end[edge][1-type]) return 1-sum_end[edge][1-type];
	double res = e[ver];
	REP(i,v[ver].size()) if(v[ver][i].second!=edge)
		res += getSumEnd(v[ver][i].second,v[ver][i].first);
	return u_sum_end[edge][type]=1,sum_end[edge][type]=res;
}


bool	u_sum_v[111111][2];
double    sum_v[111111][2];

double getSumV(int edge, int ver){
	int type = (x[edge] == ver? 0 : 1);
	if(u_sum_v[edge][type]) return sum_v[edge][type];
	if(u_sum_v[edge][1-type]) return n-2-sum_v[edge][1-type];
	double res = 0;
	REP(i,v[ver].size()) if(v[ver][i].second!=edge)
		res += getSumV(v[ver][i].second,v[ver][i].first) + 1;
	return u_sum_v[edge][type]=1,sum_v[edge][type]=res;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n-1){
		scanf("%d %d",&x[i],&y[i]);x[i]--,y[i]--;
		v[x[i]].pb(pii(y[i],i));
		v[y[i]].pb(pii(x[i],i));
	}
	REP(i,n) scanf("%lf %lf",s+i,e+i);
	double sum = 0;
	REP(i,n) sum += s[i];
	REP(i,n) s[i]/=sum;
	sum=0;
	REP(i,n) sum += e[i];
	REP(i,n) e[i]/=sum;

	double res = 0;

	REP(i,n) REP(j,v[i].size()){
		double t1 = getSumV(v[i][j].second,v[i][j].first);
		double t2 = getSumEnd(v[i][j].second, v[i][j].first);
		double t3 = getSumStart(v[i][j].second,v[i][j].first);
		res += (1-t3)*t2+ s[i] * t2 * (n-2-t1)+ t3 * (1-e[i]-t2) * (n-3-t1)-(1-s[i]-t3) * t2 * t1;
	}
	
	printf("%.10lf\n",res);

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}