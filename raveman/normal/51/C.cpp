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
int x[222222];
double t[3];

bool good(double r){
	t[1] = t[2] = t[0] = x[0] + r;
	double end =t[0] + r;
	int curr = 1;
	REP(i,n){
		if(x[i] > end){
			if(curr==3) return 0;
			t[curr] = x[i] + r;
			end = t[curr] + r;
			curr++;
		}
	}
	return 1;
}

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) scanf("%d",x+i);
	sort(x,x+n);
	double a = 0, b = 1000000000,best;
	REP(i,100){
		double s = (a+b)/2;
		if(good(s)) best=s,b=s;
		else a = s;
	}
	printf("%.6lf\n",best);
	good(best);
	sort(t,t+3);
	printf("%.6lf %.6lf %.6lf\n",t[0],t[1],t[2]);
	return 0;
}