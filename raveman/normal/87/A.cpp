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


int gcd(int a,int b){
	while(a&&b)
		if(a>b) a%=b;
		else b%=a;
	return a+b;
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int a,b;
	cin>>a>>b;
	
	int g = gcd(a,b);

	ll res = a;
	res *= b;
	res /= g;

	ll r1 = 0;
	ll r2 = 0;

	ll l1 = a;
	ll l2 = b;
	ll curr = 1;
	while(1){
		ll next = min(l1,l2);

		if(l1 < l2 || l1==l2 && a>b) r1 += (next-curr+1);
		else r2 += (next-curr+1);
		
		curr = next + 1;
		if(l1==l2) break;
		if(l1==next) l1 += a;
		if(l2==next) l2 += b;
	}
	//cout<<r1<<' '<<r2<<' '<<l1<<endl;
	if(r1==r2) puts("Equal");
	else if(r1>r2) puts("Dasha");
	else puts("Masha");

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}