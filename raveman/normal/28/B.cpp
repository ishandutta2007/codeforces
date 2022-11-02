#pragma comment(linker, "/STACK:136777216")

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

int n;
int p[111];
int d[111];
int a[111][111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif
	cin>>n;
	REP(i,n) cin>>p[i];
	REP(i,n) cin>>d[i];
	REP(i,n){
		int p1 = i-d[i];
		if(p1>=0 && p1<n) a[p1][i]=a[i][p1]=1;
		p1 = i+d[i];
		if(p1>=0 && p1<n) a[p1][i]=a[i][p1]=1;
	}
	REP(i,n) a[i][i]=1;
	REP(k,n)REP(i,n)REP(j,n)
		if(a[i][k] && a[k][j])
			a[i][j]=1;
	REP(i,n){
		vi v1,v2;
		REP(j,n){
			if(a[i][j]) v1.pb(j),v2.pb(p[j]-1);

		}
		SORT(v1),SORT(v2);
		if(v1!=v2){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}