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

int n,m;
int a[111111];
int d[111][111111];

ll qp(ll c,ll st){
	ll r=1;
	while(st){
		if(st&1)r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}

ll inv[111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	REP(i,111)inv[i]=qp(i,mod-2);

	cin>>n>>m;
	REP(i,n)scanf("%d",a+i);
	int l,r,k;
	REP(i,m){
		scanf("%d %d %d",&l,&r,&k);
		l--,r--;
		d[k][l]++;
		d[k][r+1]--;
		if(d[k][r+1]<0)d[k][r+1]+=mod;
		ll f = 1;
		for(int z=k-1;z>=0;z--){
			f*=(k-z+r-l);f%=mod;
			f*=inv[k-z];f%=mod;
			d[z][r+1]-=f;
			if(d[z][r+1]<0)d[z][r+1]+=mod;
		}
	}
	for(int i=100;i>=0;i--){
		FOR(j,1,n){
			d[i][j]+=d[i][j-1];
			if(d[i][j]>=mod)d[i][j]-=mod;
		}
		if(i){
			REP(j,n){
				d[i-1][j] += d[i][j];
				if(d[i-1][j]>=mod)d[i-1][j]-=mod;
			}
		}
	}
	REP(i,n){
		if(i)printf(" ");
		int x = a[i] + d[0][i];
		if(x>=mod)x-=mod;
		printf("%d",x);
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}