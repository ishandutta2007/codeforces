//#pragma comment(linker, "/STACK:60777216")  

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

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
int w[111111];
vi  v[111111];


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		REP(i,n)v[i].clear();
		REP(i,n)scanf("%d",w+i);
		REP(i,n-1){
			int x,y;
			scanf("%d %d",&x,&y);
			x--,y--;
			v[x].pb(y);
			v[y].pb(x);
		}
		ll sum=0;
		REP(i,n)sum+=w[i];

		vector<pii> t;
		REP(i,n)t.pb(pii(w[i],v[i].size()));
		SORT(t);
		//REP(i,t.size())cout<<t[i].first<<' '<<t[i].second<<endl;
		REP(i,n-1){
			if(i){
				while(t.back().second<=1)t.pop_back();
				sum+=t.back().first;
				t.back().second--;
			}
			cout<<sum<<' ';
		}
		puts("");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}