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
 
typedef double ll;
typedef double ull;

typedef vector<int> vi;	 
typedef pair<int,int> pii;
typedef pair<double,double> pdd;


#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

char a[222222];
char b[222222];

vi v1[30];
vi v2[30];
int n;
int u[222222];
int now;
ull same(vi v1,vi v2){
	ull res = 0;
	now++;
	REP(i,v1.size()) u[v1[i]]=now;
	REP(i,v2.size()) if(u[v2[i]]==now) res+=ull(v2[i]+1)*(n-v2[i]);
	return res;
}

ull solve(vi v1,vi v2){
	ull res = 0;
	ull sum = 0;
	REP(i,v2.size()) sum += n - v2[i];
	int pos = 0;
	REP(i,v1.size()){
		while(pos<v2.size() && v2[pos]<=v1[i]) sum -= (n - v2[pos]), pos++;
		res += sum * (v1[i] + 1);
		//cout<<"add "<<sum<<"*"<<(v1[i]+1)<<endl;
	}
	return res;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
//	n=200000;

	scanf(" %s %s",a,b);
	//REP(i,n) a[i]=b[i]='A';

	REP(i,n) v1[a[i]-'A'].pb(i);
	REP(i,n) v2[b[i]-'A'].pb(i);

	ll num = 0;
	FOR(i,1,n+1){
		ll t = n-i+1;
		num += t*t;
	}
	ull c = 0;

	REP(i,30) if(v1[i].size() && v2[i].size()){
		c += solve(v1[i], v2[i]);
		c += solve(v2[i], v1[i]);
		c += same(v1[i], v2[i]);
	}

	printf("%.10lf\n",double(c)/num);
//	cout<<num<<endl;
	//cout<<c<<endl;
	//cout<<ll(1e18)<<endl;
#ifdef LocalHost
	cerr<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}