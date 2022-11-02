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
int p[111111];
ll  a[111111];
int s[111111];
vi v[111111];

bool dfs(int ver,ll parval=0){
	if(s[ver]==-1){
		int mn = 1000000001;
		REP(i,v[ver].size()) mn=min(mn,s[v[ver][i]]);
		if(mn==1000000001){
			a[ver]=0;
			s[ver]=parval;
			return 1;
		}
		a[ver]=mn-parval;
		s[ver]=mn;
	}else{
		a[ver]=s[ver]-parval;
	}
	if(a[ver]<0) return 0;
	REP(i,v[ver].size()){
		if(!dfs(v[ver][i],s[ver])) return 0;
	}
	return 1;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n-1){
		int x;
		scanf("%d",&x);
		p[i+1]=x-1;
		v[x-1].pb(i+1);
	}
	REP(i,n)scanf("%d",s+i);
	if(!dfs(0)) puts("-1");
	else{
		ll res = 0;
		REP(i,n)res+=a[i];
		cout<<res<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}