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

int n,t;
double x[11],v[11],m[11];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
#endif

	cin>>n>>t;
	REP(i,n) cin>>x[i]>>v[i]>>m[i];

	double curr = 0;
	while(curr<t){
		double next = 1e100;

		int p1=-1,p2=-1;
		REP(i,n)REP(j,n) if(i!=j){
			double d = x[j] - x[i];
			double vv = -(v[j] - v[i]);

			if(fabs(d)>1e-9){
				double tt = d/vv;
				if(tt>0)
					if(next>tt)
						next=tt,p1=i,p2=j;
			}
		}

		bool h = 1;
		if(curr + next > t) next = t - curr,h=0;
		REP(i,n) x[i] += v[i]*next;
		curr += next;
		if(h){
			REP(i,n)REP(j,i)if(fabs(x[i]-x[j])<1e-9){
				int p1 = i;
				int p2 = j;
				double v1 = v[p1];
				double v2 = v[p2];
				v[p1] = ((m[p1]-m[p2])*v1+2*m[p2]*v2)/(m[p1]+m[p2]);
				v[p2] = ((m[p2]-m[p1])*v2+2*m[p1]*v1)/(m[p1]+m[p2]);
			}
		}
	}

	REP(i,n){
		printf("%.10lf\n",x[i]);
	}
	return 0;
}