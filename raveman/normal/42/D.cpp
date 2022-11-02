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

int f[20];
int a[20][20];


bool bad(int i,int x){
	REP(x1,i) 
		REP(x2,i) REP(x3,i)if(x2!=x3)
		if(f[x2]+f[x3] == f[x1] + x) return 1;
	return 0;
}


int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
#endif

	int n;
	cin>>n;
	
	f[0] = 1;
	f[1] = 2;
	FOR(i,2,20){
		f[i] = f[i-1] + f[i-2];
		int x = 1;
		while(bad(i,x)) x ++;
		f[i] = x;
		//cout<<f[i]<<endl;
	}
	REP(i,n)REP(j,n) a[i][j]=(i==j?0:f[i]+f[j]);

	REP(i,n){
		REP(j,n){
			if(j) cout<<' ';
			cout<<a[i][j];
		}
			
		puts("");
	}

	/*vi v;
	REP(i,n)REP(j,i) if(a[i][j]) v.pb(a[i][j]);
	SORT(v);
	cout<<v.size()<<' ';
	UN(v);
	cout<<v.size()<<endl;*/
	return 0;
}