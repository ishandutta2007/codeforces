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

int n;
int    x[555555],v[555555];
double d[555555];

#define sgn(a) (a>0?1:-1)

bool good(double t){
	REP(i,n) d[i] = x[i] + v[i]*t;
	for(int i=0;i<n;)if(v[i]>0){
		int j=i+1;
		double mx = d[i];
		while(j<n && v[j]>0) mx=max(mx,d[j]),j++;

		if(j<n){
			int k = j + 1;
			double mn = d[j];
			while(k<n && v[k]<0) mn = min(mn, d[k]), k++;

			if(mn < mx) return 1;

			j=k;
		}

		i=j;
	}else i++;
	return 0;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) scanf("%d %d",x+i,v+i);

	double a = 0, b = 1+(1e9),best=-1;

	REP(i,100){
		double s = (a+b)/2;
		if(good(s)) best=s,b=s;
		else a =s;
	}

	if(best<-0.5) puts("-1");
	else printf("%.15lf\n",best);
	return 0;
}