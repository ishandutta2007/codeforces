#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

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

bitset<300000000> b;

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
#ifndef LocalHost
	//freopen("circ.in","r",stdin);
	//freopen("circ.out","w",stdout);
#endif

	int a,bb;
	cin>>a>>bb;

	for(int i=3;i*i<=bb;i+=2)if(!b[i])
		for(int j=i*i;j<=bb;j+=2*i) b[j] = true;

	int res = 0;
	if(a<=2 && 2<=bb) res++;
	a=max(a,3);
	while(a%4!=1) a++;
	for(;a<=bb;a+=4)if(!b[a]) res++;
	cout<<res<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}