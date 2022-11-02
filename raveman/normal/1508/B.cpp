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

ll s[111111];

void solve(int n,ll k,int offset){
	for(int i=1;i<=n;i++){
		if(k>=s[n-i]){
			k-=s[n-i];
		}else{
			REP(j,i)printf("%d ",offset+i-j);
			solve(n-i,k,offset+i);
			break;
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	s[0]=1;
	ll sum=1;
	for(int i=1;i<111111;i++){
		s[i]=sum;
		sum+=s[i];
		if(sum>2e18)sum=2e18;
	}

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n;
		ll k;
		cin>>n>>k;
		if(k>s[n])puts("-1");
		else{
			k--;
			solve(n,k,0);
			puts("");
		}
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}