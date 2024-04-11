#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <cassert>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

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

int n,m;
int c[1111][1111];
int s[1111];
typedef pair<ll,ll> pl;

pl solvex(){
	pl best;
	best.first = 1e18;
	CL(s,0);
	
	REP(i,n)REP(j,m) s[i] += c[i][j];

	REP(i,n+1){
		ll temp = 0;
		int x = i * 4;
		REP(j,n){
			int X = j * 4 + 2;
			ll cost = ll(X-x)*(X-x)*ll(s[j]);
			temp += cost;
		}
		if(best.first > temp) best = pl(temp,i);
	}

	return best;
}
pl solvey(){
	pl best;
	best.first = 1e18;
	CL(s,0);
	
	REP(i,n)REP(j,m) s[j] += c[i][j];

	REP(i,m+1){
		ll temp = 0;
		int x = i * 4;
		REP(j,m){
			int X = j * 4 + 2;
			ll cost = ll(X-x)*(X-x)*ll(s[j]);
			temp += cost;
		}
		if(best.first > temp) best = pl(temp,i);
	}

	return best;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n) REP(j,m) scanf("%d",&c[i][j]);

	pl s1 = solvex();
	pl s2 = solvey();

	cout<<s1.first + s2.first<<endl;
	cout<<s1.second<<' '<<s2.second<<endl;

#ifdef LocalHost
	cerr<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}