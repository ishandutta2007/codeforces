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
int x[444],y[444];

pair<int,double> e[844][844];
vi v[844];

double COST;

const double eps = 1e-8;

double c[844];
int fr[844];


bool pushflow(){
	int from = n + n;
	int to = n + n + 1;
	REP(i,to+1) c[i] = 1e100;

	priority_queue< pair<double, int> > q;
	c[from] = 0;
	q.push(make_pair(0, from));
	CL(fr,-1);

	while(!q.empty()){
		double cst = -q.top().first;
		int ver = q.top().second;
		q.pop();
		if(ver==to) continue;
		if(c[ver]<cst-eps) continue;
		
		REP(i,v[ver].size()){
			int nx = v[ver][i];
			if(e[ver][nx].first>0){
				double ncst = cst + e[ver][nx].second;
				if(ncst < c[nx] - 2*eps){
					c[nx] = ncst;
					fr[nx] = ver;
					q.push(make_pair(-ncst,nx));
				}
			}
		}
	}

	if(c[to]<1e50){
		COST = c[to];

		int curr = to;
		while(curr!=from){
			int prev = fr[curr];
			e[prev][curr].first--;
			e[curr][prev].first++;
			curr=prev;
		}
		return 1;
	}
	return 0;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) scanf("%d %d",x+i,y+i);
	REP(i,n)REP(j,n)if(y[i]>y[j]){
		v[j].pb(i+n);
		v[i+n].pb(j);
		e[j][i+n]=make_pair(1,hypot(x[i]-x[j],y[i]-y[j]));
		e[i+n][j].second=-hypot(x[i]-x[j],y[i]-y[j]);
	}
	REP(i,n){
		v[n+n].pb(i);
		v[i].pb(n+n);
		e[n+n][i].first=1;
	}
	REP(i,n){
		v[i+n].pb(n+n+1);
		v[n+n+1].pb(i+1);
		e[i+n][n+n+1].first=2;
	}

	int flow = 0;
	double cost = 0;

	while(1){
		bool x = pushflow();
		if(!x) break;
		flow++;
		cost += COST;
	}

	while(flow>=n);
	if(flow!=n-1) puts("-1");
	else printf("%.10lf\n",cost);
	
#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}