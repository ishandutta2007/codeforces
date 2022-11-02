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

const int mod = 1000000007;

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

	int tc;
	cin>>tc;
	while(tc){
		tc--;
		double R,r,k;
		cin>>R>>r>>k;
		double x1 = 0.5/R;
		double x2 = 0.5/r;
		double x = (x1+x2)/2;
		double y = (x2-x1)*k;
		double d = sqrt(x*x+y*y);
		double rr = (x2-x1)/2.;
		printf("%.10lf\n",(1/(d-rr)-1/(d+rr))/2.);
	}
	return 0;
}