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
typedef pair<double,double>	pdd;
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
const int m2 = 999999997;
int n;
int sa[1<<20],sb[1<<20];
int id[1<<20];
int ea[1<<20],eb[1<<20];

ll p[1<<20];
ll p2[1<<20];

vector<pii> solve(int* s, int* e){
	vector<pii> events;
	REP(i,n)events.pb(pii(s[i]*2,id[i]));
	REP(i,n)events.pb(pii(e[i]*2+1,id[i]));
	SORT(events);
	vector<pii> a;
	ll sum=0,sum2=0;
	for(int i=0;i<events.size();){
		int j = i;
		if(events[i].first%2==1 && events[i-1].first%2==0)
			a.pb(pii(sum,sum2));

		while(j<events.size() && events[i].first==events[j].first){
			if(events[j].first%2==0){
				sum = (sum + p[events[j].second])%mod;
				sum2 = (sum2+ p2[events[j].second])%m2;
			}else{
				sum = (sum + mod - p[events[j].second])%mod;
				sum2 = (sum2 + m2 - p2[events[j].second])%m2;
			}
			++j;
		}

		i=j;
	}
	UN(a);
	return a;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	p[0]=1;
	p2[0]=1;
	FOR(i,1,1<<20)p[i]=p[i-1]*2%mod;
	FOR(i,1,1<<20)p2[i]=p2[i-1]*2%m2;
	cin>>n;
	REP(i,n)id[i]=i;
	random_shuffle(id,id+n);
	REP(i,n)scanf("%d %d %d %d",sa+i,ea+i,sb+i,eb+i);
	vector<pii> s1 = solve(sa,ea);
	vector<pii> s2 = solve(sb,eb);
	puts(s1==s2?"YES":"NO");
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}