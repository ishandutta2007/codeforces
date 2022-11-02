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

int n,q;
int u[222222];
int  m[222222];
int  M[222222];
int  a[222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>q;
	REP(i,n)scanf("%d",a+i);
	
	REP(i,n)if(!u[a[i]])u[a[i]]++,m[a[i]]=i,M[a[i]]=i;
	else{
		u[a[i]]++;
		m[a[i]]=min(m[a[i]],i);
		M[a[i]]=max(M[a[i]],i);
	}
	vector<pii> v;
	REP(i,222222)if(u[i])v.pb(pii(m[i],M[i]));
	SORT(v);
	int nc=0;
	for(int i=0;i<v.size();){
		int from = v[i].first;
		int to = v[i].second;
		int t = 0;
		int j = i;
		while(j<v.size() && v[j].first<=to){
			t=max(t,u[a[v[j].first]]);
			to=max(v[j].second,to);
			j++;
		}
		nc+=t;
		i=j;
	}

	cout<<n-nc<<endl;

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}