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

int n,m;
ll d[600][600];
vector<pii> v[600];

ll cv[600];
ll cd[600];

bool u[600*600];
int e1[600*600];
int e2[600*600];
int e3[600*600];

vi re[666];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)REP(j,n)d[i][j]=1e18;
	REP(i,n)d[i][i]=0;
	REP(i,m){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		x--,y--;
		d[x][y]=z;
		d[y][x]=z;
		e1[i]=x;
		e2[i]=y;
		e3[i]=z;
		re[x].pb(i);
		re[y].pb(i);
	}
	REP(k,n)REP(i,n)REP(j,n)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

	int q;
	cin>>q;
	REP(i,q){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		x--,y--;
		v[x].pb(pii(y,z));
		v[y].pb(pii(x,z));
	}

	int ov;
	int ei;
	REP(i,n){
		CL(cv,0);
		REP(j,v[i].size())cv[v[i][j].first]=v[i][j].second;
		REP(j,n){
			ll best=0;
			REP(k,n)best=max(best,cv[k]-d[j][k]);
			REP(k,re[j].size()){
				ei = re[j][k];
				ov = e1[ei]+e2[ei]-j;
				if(e3[ei]+d[i][ov]<=best){
					u[ei]=1;
					//cout<<i<<' '<<j<<' '<<ov<<" = "<<ei<<' '<<best<<' '<<e3[ei]<<' '<<d[i][ov]<<endl;
				}
			}
		}
	}
	int w=0;
	REP(i,m)if(u[i]){
		w++;
		//cout<<i<<endl;
	}
	cout<<w<<endl;
	


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}