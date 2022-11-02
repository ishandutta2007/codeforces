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
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

pdd p[3];

const double pi = acos(-1.);


int main(){
#ifdef LocalHost    
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
#endif

	double res = 1e100;
	REP(i,3) cin>>p[i].first>>p[i].second;
	sort(p,p+3);
	do{
		FOR(i,1,101) FOR(j,1,101-i) FOR(k,1,101-j-i){
			int n = i + j + k;
			double a1 = 2 * pi * i / n;
			double a2 = 2 * pi * j / n;
			double a3 = 2 * pi * k / n;
			
			double d1 = hypot(p[0].first - p[1].first, p[0].second - p[1].second);
			double d2 = hypot(p[1].first - p[2].first, p[1].second - p[2].second);
			double d3 = hypot(p[2].first - p[0].first, p[2].second - p[0].second);

			double r1 = d1 * d1 / 2 / (1 - cos(a1));
			double r2 = d2 * d2 / 2 / (1 - cos(a2));
			double r3 = d3 * d3 / 2 / (1 - cos(a3));

			if(fabs(1-r1/r2)<1e-4 && fabs(1-r1/r3)<1e-4){
				res= min(res,r1 * sin(2*pi / n) * n / 2);
			}
		}
	}while(next_permutation(p, p+3));

	printf("%.6lf\n",res);

    return 0;
}