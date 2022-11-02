#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
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

int a[111111];
ll  c[222222];
int n,l,v1,v2;
double d[444444];
double res[111111];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>l>>v1>>v2;
	REP(i,n) scanf("%d",a+i);
	REP(i,n) c[i]=a[i];
	REP(i,n) c[i+n]=c[i]+l+l;
	REP(i,n) d[i] = a[i];
	REP(i,n) d[i+n] = d[i]+l+l;
	double DIST = double(l)/(v1+v2)*v2;
	REP(i,2*n) d[i+2*n] = d[i] - DIST;
	d[4*n]=0;
	d[4*n+1]=l+l;
	sort(d,d+4*n+2);
	FOR(i,1,4*n+2){
		if(d[i]>l+l) break;
		if(d[i-1]<-1e-10) continue;
		double len = d[i]-d[i-1];
		//cout<<d[i]<<' '<<len<<endl;
		if(len>1e-10){
			double s = (d[i-1]+d[i])/2;
			double e = s + DIST;
			int p1 = lower_bound(c,c+2*n,e-1e-10)-c-1;
			int p2 = lower_bound(c,c+2*n,s-1e-10)-c;
			int diff = p1 - p2 + 1;
			if(diff>=0) res[diff] += len;
		}
	}

	REP(i,n+1)
		printf("%.10lf\n",res[i]/2/l);

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}