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

int b[222222];
bool u[222222];
bool w[222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n;
		scanf("%d",&n);
		REP(i,n)u[i]=w[i]=0;
		REP(i,n)scanf("%d",b+i),b[i]--,u[b[i]]=1;
		vector<pii> v;
		REP(i,n)if(!u[i]){
			int t = i,p=i;
			while(!w[t]){
				w[t]=1;
				p=t;
				t=b[t];
			}
			v.pb(pii(i,p));
		}
		int res = n;
		if(v.size()==1){
			res--;
			b[v[0].second]=v[0].first;
		}else{
			REP(i,v.size()){
				b[v[i].second]=v[(i+1)%v.size()].first;
				res--;
			}
		}
		cout<<res<<"\n";
		REP(i,n)printf("%d ",b[i]+1);puts("");
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}