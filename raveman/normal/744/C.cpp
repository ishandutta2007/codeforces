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
#include<stack>
#include<unordered_map>
#include<unordered_set>

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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n;
char c[16];
int r[16];
int b[16];
int d[1<<16][122];

int nb[1<<16];
int nr[1<<16];


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	int sumr=0,sumb=0;
	REP(i,n)cin>>c[i]>>r[i]>>b[i],sumr+=r[i],sumb+=b[i];
	REP(i,1<<n){
		nb[i]=nr[i]=0;
		REP(j,n)if(i&(1<<j)){
			if(c[j]=='R')nr[i]++;
			else nb[i]++;
		}
	}
	CL(d,-1);
	d[0][0]=0;
	int nj,tmp;
	REP(mask,1<<n){
		REP(j,121)if((tmp=d[mask][j])!=-1){
			REP(k,n)if(!(mask&(1<<k))){
				nj = j + min(r[k],nr[mask]);
				d[mask|(1<<k)][nj]=max(d[mask|(1<<k)][nj],tmp+min(b[k],nb[mask]));
			}
		}
	}

	int res = max(sumr,sumb)+n;
	REP(i,121)if(d[(1<<n)-1][i]!=-1){
		res=min(res,max(sumr-i,sumb-d[(1<<n)-1][i])+n);
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}