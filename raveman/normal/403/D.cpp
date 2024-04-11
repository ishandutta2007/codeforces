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

const int mod = 1000000007 ;

int d[111][1111];
ll r[55][1111];
ll c[1111][1111];
vector<pii> dd[1111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	REP(i,1111){
		c[i][i]=c[i][0]=1;
		FOR(j,1,i)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	d[0][0]=1;
	for(int diff=0;diff<=1000;diff++){
		for(int i=100;i>=0;i--)REP(j,1111)if(d[i][j] && j+diff<=1000){
			d[i+1][j+diff]+=d[i][j];
			if(d[i+1][j+diff]>=mod)d[i+1][j+diff]-=mod;
		}
	}
	REP(i,1111)REP(j,1111)if(d[i][j])dd[i].pb(pii(j,d[i][j]));
	CL(r,-1);
	int tc;
	cin>>tc;
	REP(TC,tc){
		int n,k;
		scanf("%d %d",&n,&k);
		if(k>50){
			puts("0");
			continue;
		}
		ll res = 0;
		if(r[k][n]!=-1)res=r[k][n];
		else{
			REP(ii,dd[k].size()){
				int i = dd[k][ii].first;
				int nn = n - i - k;
				if(nn>=0){
					res += dd[k][ii].second * ll(c[nn+k][k]);
					res %= mod;
				}
		}

			FOR(ii,2,k+1)res*=ii,res%=mod;
			r[k][n]=res;
		}
		printf("%d\n",(int)(res));
	}



#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}