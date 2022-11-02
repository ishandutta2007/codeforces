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

const int mod = 1000000007;

string s,t;
int d[5555][5555];

int go(int a,int b){
	if(b<0 || a<0) return 0;
	if(d[a][b]!=-1) return d[a][b];
	int res = go(a,b-1);
	if(s[a]==t[b]){
		res ++;
		res += go(a-1,b-1);
		if(res>=mod) res-=mod;
	}
	//cout<<a<<' '<<b<<": "<<res<<endl;
	return d[a][b] = res;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>s>>t;
	CL(d,-1);
	int res = 0;
	REP(i,s.size()){
		//cout<<i<<' '<<" : " <<go(i,t.size()-1)<<endl;
		res += go(i,t.size()-1);
		if(res>=mod) res-=mod;
		//break;
	}
	cout<<res<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}