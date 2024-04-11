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


int z[333333];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n,x;
		cin>>n;
		REP(i,n+1)z[i]=-1;
		vector<pii> v;
		REP(i,n)scanf("%d",&x),v.pb(pii(x,i));
		SORT(v);
		for(int i=0;i<v.size();){
			int j = i;
			vi t;
			while(j<v.size() && v[j].first==v[i].first){
				t.pb(v[j].second);
				j++;
			}

			int mg = t[0];
			FOR(k,1,t.size())mg=max(mg,t[k]-t[k-1]-1);
			mg = max(mg,n-1-t.back());

			//cout<<mg<<' '<<v[i].first<<endl;

			if(z[mg+1]==-1 || z[mg+1]>v[i].first)z[mg+1]=v[i].first;
			i=j;
		}
		int t = -1;
		for(int i=0;i<=n;i++){
			if(t==-1)t=z[i];
			else if(z[i]!=-1)t=min(t,z[i]);
			z[i]=t;
		}
		FOR(i,1,n+1)cout<<z[i]<<' ';puts("");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}