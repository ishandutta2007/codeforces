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

int n;
int h[3333],r[3333],R[3333];
double p[3333];

double w(int i,int j){
	if(r[i] >= R[j]) return h[j];

	double res = 0;

	if(R[i] >= R[j]){
		double hh = (R[j] - r[i]) * h[i] / (R[i] - r[i] + 0.);
		res = max(res, h[j] - hh);
	}

	if(R[i] < R[j]){
		double hh = (R[i] - r[j]) * h[j] / (R[j] - r[j] + 0.);
		res = max(res, hh - h[i]);		
	}

	if(r[i] >= r[j]){
		double hh = (r[i] - r[j]) * h[j] / (R[j] - r[j] + 0.);
		res = max(res, hh);		
	}


	
	return res;
}

int main(){
	freopen("input.txt","r",stdin);
#ifndef LocalHost    
    freopen("output.txt","w",stdout);
#endif
	cin>>n;
	REP(i,n) scanf("%d %d %d",&h[i],&r[i],&R[i]);

	FOR(i,1,n){
		double pos = 0;
		REP(j,i) pos = max(pos , w(i,j) + p[j]);
		p[i] = pos;
	}

	double hmax = 0;
	REP(i,n) hmax = max(hmax, p[i] + h[i]);
	printf("%.8lf\n",hmax);

	return 0;
}