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
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
int a[222222];
vi v[222222];


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		REP(i,n)scanf("%d",a+i);
		REP(i,n+1)v[i].clear();
		REP(i,n)v[a[i]].pb(i);
		REP(i,n+1)reverse(v[i].begin(),v[i].end());
		vi res;

		int pos = -1;
		while(pos<n-1){
			int x = 0;
			int mx=pos+1;
			for(x=0;;x++){
				while(v[x].size()>0 && v[x].back()<=pos)v[x].pop_back();
				if(v[x].size()==0) break;
				mx=max(mx,v[x].back());
			}
			if(mx==-1)break;
			res.pb(x);
			pos=mx;
		}

		cout<<res.size()<<endl;
		REP(i,res.size()) printf("%d ",res[i]);
		puts("");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}