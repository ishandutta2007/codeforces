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

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif

	int n,m;
	int a[1111];
	map<string,int> q;
	cin>>n>>m;
	REP(i,n) cin>>a[i];
	sort(a,a+n);
	REP(i,m){
		string x;
		cin>>x;
		q[x]++;
	}
	vi v;
	for(map<string,int>::iterator it= q.begin();it!=q.end();it++)
		v.pb(it->second);
	SORT(v);

	int r1=0,r2=0;
	REP(i,v.size()) r1 += a[i] * v[v.size()-1-i];
	REP(i,v.size()) r2 += a[n-i-1] * v[v.size()-1-i];
	cout<<r1<<' '<<r2<<endl;

    return 0;
}