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

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

	int n;
	cin>>n;
	vi r;
	int curr = 1;
	REP(i,n){
		int x;
		cin>>x;
		if(x==curr) curr++,r.pb(i+2001);
	}
	cout<<r.size()<<endl;
	REP(i,r.size()) printf("%d ",r[i]);


	return 0;
}