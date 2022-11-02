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

int n,m;
int a[111111];
vi  v[111111];


int  p[111111];
int sz[111111];

int P(int x){return p[x]==x?x:p[x]=P(p[x]);}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)scanf("%d",a+i);
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	vector<pii> t;
	REP(i,n)t.pb(pii(a[i],i)),p[i]=i,sz[i]=0;
	SORT(t);
	reverse(t.begin(),t.end());
	double res = 0;
	REP(i,n){
		int ver = t[i].second;
		sz[ver]=1;
		REP(j,v[ver].size()){
			if(P(v[ver][j])!=P(ver) && sz[P(v[ver][j])]){
				res += double(sz[ver])*double(sz[P(v[ver][j])]) * t[i].first*2;
				sz[ver] += sz[P(v[ver][j])];
				p[P(v[ver][j])]=ver;				
			}
		}
	}
	printf("%.10lf\n",res/n/(n-1));
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}