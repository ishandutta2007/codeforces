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

int n,m;
char s[22][22];

set<string> q;

bool good(int x, int y){
	q.clear();
	REP(i,n/x) REP(j,m/y){
		string sm = "Z";
		sm[0]++;

		int sx = i*x, sy = j*y;
		string ss;
		REP(ii,x) REP(jj,y) ss.pb(s[sx+ii][sy+jj]);
		if(q.count(ss)) return 0;
		sm = min(sm, ss);

		ss="";
		REP(ii,x) REP(jj,y) ss.pb(s[sx+x-1-ii][sy+y-1-jj]);
		if(q.count(ss)) return 0;
		sm = min(sm, ss);

		if(x==y){
			ss="";
			REP(jj,y) REP(ii,x) ss.pb(s[sx+ii][sy+y-1-jj]);
			if(q.count(ss)) return 0;
			sm = min(sm, ss);

			ss="";
			REP(jj,y) REP(ii,x) ss.pb(s[sx+x-1-ii][sy+jj]);
			if(q.count(ss)) return 0;
			sm = min(sm, ss);
		}

		q.insert(sm);
	}
	return 1;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif
	cin>>n>>m;
	REP(i,n) scanf(" %s",s[i]);
good(2,3);
	int num = 0;
	int x = n, y = m;
	FOR(i,1,n+1) if(n%i==0) FOR(j,1,m+1) if(m%j==0)
		if(good(i,j)){
			num++;
			if(i*j < x*y || i*j==x*y && i<x) x = i, y = j; 
		}
	cout<<num<<endl<<x<<' '<<y<<endl;


	return 0;
}