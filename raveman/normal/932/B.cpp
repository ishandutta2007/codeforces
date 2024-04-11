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

int f[1111111];
int g[1111111];

vi v[11];

int solve(int to,int k){
	return lower_bound(v[k].begin(),v[k].end(),to+1)-v[k].begin();
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	REP(i,1111111){
		f[i]=1;
		int t = i;
		while(t){
			if(t%10){
				f[i]*=(t%10);
			}
			t/=10;
		}
		if(i<10)g[i]=i;
		else g[i]=g[f[i]];

		v[g[i]].pb(i);
	}

	int q;
	cin>>q;
	REP(Q,q){
		int l,r,k;
		scanf("%d %d %d",&l,&r,&k);
		cout<<solve(r,k)-solve(l-1,k)<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}