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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back	

int n,k;
ll a[55];

int d[55][55];

ll MASK;

bool good(int n,int k){
	if(n<k) return 0;
	if(d[n][k]!=-1)return d[n][k];
	if(k==1){
		ll sum=0;
		REP(i,n)sum+=a[i];
		return d[n][k]=((sum&MASK)==MASK)?1:0;
	}
	ll sum=0;
	for(int i=n-1;i>=0;i--){
		sum += a[i];
		if((sum&MASK)==MASK){
			if(good(i,k-1)){
				return d[n][k]=1;
			}
		}
	}
	return d[n][k]=0;
}

bool good(ll mask){
	CL(d,-1);
	MASK=mask;
	return good(n,k);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	REP(i,n)cin>>a[i];
	ll res = 0;
	for(ll i=59;i>=0;i--){
		if(good(res|(1ll<<i)))  res |= (1ll<<i);
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}