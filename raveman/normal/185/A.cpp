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

struct M{
	ll a[2][2];
	M(){CL(a,0);}
	M mul(M m){
		M r;
		REP(i,2)REP(j,2)REP(k,2)
			r.a[i][j] = (r.a[i][j] + a[i][k]*m.a[k][j])%mod;
		return r;
	}
};

M qp(M m,ll n){
	M r;
	r.a[0][0]=r.a[1][1]=1;
	while(n){
		if(n&1) r =r.mul(m);
		m=m.mul(m);
		n>>=1;
	}
	return r;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	ll n;
	cin>>n;
	M m;
	m.a[0][0]=3;
	m.a[0][1]=1;
	m.a[1][0]=1;
	m.a[1][1]=3;
	m=qp(m,n);
	cout<<m.a[0][0]<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}