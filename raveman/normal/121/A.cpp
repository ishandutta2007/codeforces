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

vector<ll> v;
void go(ll n){
	if(n>4444444444ll) return;
	if(n) v.pb(n);
	go(n*10+4);
	go(n*10+7);
}

ll f(int n){
	ll sum = 0;
	REP(i,v.size()){
		if((min(ll(n),v[i])-(i?v[i-1]:0))<=0) break;
		sum += v[i] * ll(min(ll(n),v[i])-(i?v[i-1]:0));

	}
	return sum;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	go(0);
	SORT(v);
	int a,b;
	cin>>a>>b;
	cout<<f(b)-f(a-1)<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}