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

const int mod = 998244353 ;
int n;
ll f[1111111];
ll s[1111111];
int p[1111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	for(int i=2;i<=1000000;i++)if(p[i]==0){
		for(int j=i+i;j<=1000000;j+=i){
			p[j]=i;
		}
	}

	cin>>n;

	f[0]=1;
	FOR(i,1,1000001){
		int t = i;
		int c=1;
		while(p[t]!=0){
			int w = p[t];
			int nm=1;
			while(t%w==0){
				t/=w;
				nm++;
			}
			c*=nm;
		}
		if(t>1){
			c*=2;

		}

		f[i]=(s[i-1]+c)%mod;
		s[i]=(s[i-1]+f[i])%mod;
		//cout<<i<<"="<<f[i]<<endl;
	}
	cout<<f[n]<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}