#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
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

int d[22222222];
int solve(int n){
	int nn = n;
	int s = 1;
	while(n>1){
		int p = d[n] == 0 ? n : d[n];
		int c = 0;
		while(n%p==0) n/=p,c++;
		REP(i,c/2) s*=p;
	}
	return nn/s/s;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	for(int i=2;i<20000;i++)if(d[i]==0)
		for(int j=i*i;j<20000000;j+=i) d[j]=i;
	ll res = 0;
	int n,a;
	cin>>a>>n;
	REP(i,n){
		res += solve(a);
		a++;
	}
	cout<<res<<endl;
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}