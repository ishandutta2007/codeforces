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

double solve(int a,int b){
	if(b==0) return 1.;
	if(a==0) return 0.5;
	
	double res = 0.5;
	if(a>=4*b){
		res += 0.5;
		res -= b/double(a);
	}else{
		res += a / 16./b;
	}
	return res;
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int a,b;
		cin>>a>>b;
		printf("%.10lf\n",solve(a,b));
	}
	return 0;
}