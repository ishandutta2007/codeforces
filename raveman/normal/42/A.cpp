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

int a[22],b[22];

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
#endif

	int n,v;
	cin>>n>>v;
	REP(i,n) cin>>a[i];
	REP(i,n) cin>>b[i];

	double res = v;
	double mx = 1e100;
	REP(i,n) mx = min(mx, double(b[i])/a[i]);
	double sum = 0;
	REP(i,n) sum += a[i]*mx;
	res = min(res,sum);
	printf("%.10lf\n",res);

	return 0;
}