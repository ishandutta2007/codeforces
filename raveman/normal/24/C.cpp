#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
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

int X,Y;
int x[111111];
int y[111111];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

	int n;
	ll m;
	cin>>n>>m;
	m%=(2*n);
	cin>>X>>Y;
	REP(i,n) scanf("%d %d",x+i,y+i);
	REP(i,m){
		X = 2*x[i%n]-X;
		Y = 2*y[i%n]-Y;
	}
	cout<<X<<' '<<Y<<endl;
	return 0;
}