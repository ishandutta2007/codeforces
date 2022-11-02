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
int l[1111];
int r[1111];
int a[1111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)cin>>l[i];
	REP(i,n)cin>>r[i];
	CL(a,-1);
	int rem = n;

	while(rem){
		vi v;
		REP(i,n)if(l[i]==0 && r[i]==0 && a[i]==-1){
			v.pb(i);
		}
		if(v.empty()){
			puts("NO");
			return 0;
		}
		REP(i,v.size())a[v[i]]=rem;
		rem-=v.size();
		REP(i,n)if(a[i]==-1){
			REP(j,v.size()){
				if(v[j]<i) l[i]--;
				else r[i]--;
			}
		}
	}

	puts("YES");
	REP(i,n){
		printf("%d ",a[i]);
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif

	return 0;
}