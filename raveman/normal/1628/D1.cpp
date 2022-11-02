#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m,k;
const int mod = 1000000007;
ll c[2222][2222];

ll qp(ll c, ll st){
	ll r=1;
	while(st){
		if(st&1)r*=c,r%=mod;
		st>>=1;
		c*=c;c%=mod;
	}

	return r;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	ll i2 = qp(2,mod-2);

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>m>>k;
		REP(i,n+1)REP(j,i+1){
			if(j==0)c[i][j]=0;
			else if(j==i)c[i][j]=(c[i-1][j-1]+k)%mod;
			else c[i][j]=(((c[i-1][j-1]+c[i-1][j])%mod)*i2)%mod;
			//cout<<i<<' '<<j<<' '<<c[i][j]<<endl;
		}
		cout<<c[n][m]<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}