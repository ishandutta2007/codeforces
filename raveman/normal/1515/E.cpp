//#pragma comment(linker, "/STACK:60777216")  

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

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

ll n,M;
ll f[444];
ll c[444][444];
ll r[444][444];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>M;

	REP(i,444){
		c[i][0]=c[i][i]=1;
		FOR(j,1,i)c[i][j]=(c[i-1][j]+c[i-1][j-1])%M;
	}

	FOR(i,1,444){
		for(int p=1;p<=i;p++){
			f[i]=(f[i]+c[i-1][p-1])%M;
		}
	}
	f[1]=1;
	FOR(i,2,444)f[i]=(f[i-1]*2)%M;

	FOR(i,1,n+1){
		r[i][1]=f[i];
		for(int g=2;g<=i;g++){
			if(g+g-1>i)continue;
			for(int s=1;s<=i;s++)
				if(i-s-1>=g-1+g-1-1){
				r[i][g]=(r[i][g] + ((r[i-s-1][g-1]*f[s])%M)*c[i-(g-1)][s])%M;
			}
		}
	}


	ll s=0;
	REP(g,n+1)s=(s+r[n][g])%M;
	cout<<s<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}