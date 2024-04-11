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
int x[3333],y[3333];
bool u[3333];
ll d[3333];

void solve(int n){
	ll val = y[n-1] + d[n-1];
	ll sum = 0;
	for(int i=n-1;i>=0;i--){
		val = min(val, y[n-1] + sum + d[i]);
		if(i-1>=0) sum += x[n-1] - x[i-1];
	}
	d[n] = val;
}

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	cin>>n;
	REP(i,n) scanf("%d %d",x+i,y+i),x[i]=-x[i];

	REP(i,n)REP(j,i)if(x[i]<x[j])
		swap(x[i],x[j]),swap(y[i],y[j]);
	
	FOR(i,1,n+1) solve(i);
	cout<<d[n]<<endl;
	return 0;
}