#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
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

using namespace std;


typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

const int mod = 1000000007;

int n,k;
int d[501][501];
ll pw[555*555];


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	pw[0]=1;
	FOR(i,1,555*555)pw[i]=pw[i-1]*2%mod;

	cin>>n>>k;
	//n=k=500;
	d[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			ll sum = 0;
			for(int prev=0;prev<i;prev++){
				sum = (sum + d[prev][j-1] * (pw[(i-prev)*(prev+1)]-pw[(i-prev)*prev]+mod))%mod;
			}
			d[i][j] = sum%mod;
		}
	}
	ll sum  = 0;
	REP(i,n+1) sum = (sum + d[i][k] * pw[(n-i)*i]%mod)%mod;
	cout<<sum<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}