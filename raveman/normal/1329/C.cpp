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
typedef pair<int,pii>	p3;
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

int h,g;
int a[1<<20];

bool dfs(int ver){
	int lfn = 2 * ver;
	int rgn = 2 * ver + 1;
	if ((lfn>=(1<<h) || a[lfn]==0) && (rgn>=(1<<h) || a[rgn]==0)){
		if(ver>=(1<<g)){
			a[ver]=0;
			return 1;
		}
		return 0;
	}else{
		if(a[lfn]>a[rgn]){
			int z = a[lfn];
			bool t= dfs(lfn);
			if(t)a[ver]=z;
			return t;
		}else{
			int z = a[rgn];
			bool t = dfs(rgn);
			if(t)a[ver]=z;
			return t;
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>h>>g;
		FOR(i,1,(1<<h))scanf("%d",a+i);
		vi res;
		FOR(i,1,(1<<g)){
			while(dfs(i))res.pb(i);
		}
		ll sum=0;
		FOR(i,1,(1<<g))sum+=a[i];
		cout<<sum<<"\n";
		REP(i,res.size())cout<<res[i]<<' ';
		cout<<"\n";
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}