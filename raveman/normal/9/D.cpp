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

 ll d[44][44];
bool u[44][44];

ll go(int n,int h){
	if(n==0) return h==0;
	if(n==1) return h==1;
	if(h==0) return 0;
	if(u[n][h]) return d[n][h];
	ll res = 0;
	REP(i,n){
		REP(h1,h)REP(h2,h)if(h1==h-1 || h2==h-1)
			res+=go(i,h1)*go(n-i-1,h2);
	}
	return u[n][h]=1,d[n][h]=res;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif

	int n,h;
	cin>>n>>h;

	ll sum = 0;
	FOR(i,h,n+1) sum += go(n,i);
	cout<<sum<<endl;


	return 0;
}