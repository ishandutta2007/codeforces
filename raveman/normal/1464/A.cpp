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

int x[111111];
int y[111111];
bool u[111111];
int idr[111111];
int idc[111111];
vi c;

void dfs(int ver){
	if(ver<0)return;
	if(u[ver])return;
	c.pb(ver);
	u[ver]=1;
	dfs(idc[x[ver]]);
	dfs(idr[y[ver]]);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n,m;
		cin>>n>>m;
		REP(i,n)idr[i]=-1,idc[i]=-1;
		REP(i,m){
			scanf("%d %d",x+i,y+i);
			x[i]--,y[i]--;
			idr[x[i]]=i;
			idc[y[i]]=i;
			u[i]=0;
		}
		int res=0;
		REP(i,m)if(!u[i]){
			c.clear();
			dfs(i);
			vi xx,yy;
			REP(j,c.size())xx.pb(x[c[j]]),yy.pb(y[c[j]]);
			UN(xx);
			UN(yy);
			if(x[i]==y[i])continue;
			if(xx==yy)res+=(xx.size()+1);
			else res+=xx.size();

		}
		cout<<res<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}