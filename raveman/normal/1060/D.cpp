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
int l[111111];
int r[111111];
multiset<pii> s1,s2;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n){
		scanf("%d %d",l+i,r+i);
		s1.insert(pii(-l[i],-r[i]));
		s2.insert(pii(-r[i],-l[i]));
	}
	ll res = 0;
	while(!s1.empty()){
		pii p1 = *s1.begin();
		pii p2 = *s2.begin();
		res += 1 + max(-p1.first,-p2.first);

		s1.erase(s1.begin());
		s2.erase(s2.begin());
		if(p1.first==p2.second && p1.second==p2.first){
			continue;
		}else{
			s1.erase(s1.find(pii(p2.second,p2.first)));
			s2.erase(s2.find(pii(p1.second,p1.first)));
			s1.insert(pii(p2.second,p1.second));
			s2.insert(pii(p1.second,p2.second));
		}
	}
	cout<<res<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}