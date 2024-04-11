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
ll    b[111111];


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%I64d",&b[i]);

	vector<ll> s;
	for(ll j=59;j>=0;j--){
		vector<ll> v;
		REP(i,n)if(b[i]!=-1 && (b[i]&(1ll<<j))){
			v.pb(b[i]);
			b[i]=-1;
		}

		if(v.empty()) continue;

		vector<ll> ns;
		ns.pb(v[0]);
		int pos = 1;
		REP(i,s.size()){
			ns.pb(s[i]);
			if(s[i]&(1ll<<j)){
				if(pos<v.size()) ns.pb(v[pos]),pos++;
			}
		}
		if(pos<v.size()){
			puts("No");
			return 0;
		}
		s=ns;
	}
	puts("Yes");
	REP(i,s.size())cout<<s[i]<<' ';puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}