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

int n;
ll  k;
int p[1<<20];
ll  w[1<<20];
ll  X[1<<20];
ll ranges[1<<20];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	FOR(i,1,n)scanf("%d %I64d",p+i,w+i),p[i]--,X[i]=w[i]^X[p[i]];
	sort(X,X+n);

	ll res = 0;
	for(ll i=61;i>=0;i--){
		ll num = 0;
		REP(j,n){
			ll B = res>>(i+1);
			ll A = X[j]>>(i+1);
			ll T = (A^B)<<(i+1);
			ranges[j]=T+((X[j]&(1ll<<i))?(1ll<<i):0);
		}
		sort(ranges,ranges+n);
		int p1=0,p2=0;
		REP(j,n){
			while(p1<n && X[p1]<ranges[j])p1++;
			while(p2<n && ranges[j]+(1ll<<i)>X[p2])p2++;
			num += p2-p1;
		}
		if(num>=k){
			continue;
		}else{
			k -= num;
			res ^= (1ll<<i);
		}
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}