//#pragma comment(linker, "/STACK:60777216")  

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
#include<stack>

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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,m;
vi v[3333];

int d[3333][3333];

pii ds[3333][3333];
pii invds[3333][3333];

void solve(int* d,int ver){
	d[ver]=0;
	queue<int> q;
	q.push(ver);
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		REP(i,v[curr].size()){
			int next = v[curr][i];
			if(d[next]==-1){
				d[next] = d[curr] + 1;
				q.push(next);
			}
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y;
		cin>>x>>y;
		x--,y--;
		v[x].pb(y);
	}

	CL(d,-1);
	REP(i,n) solve(d[i],i);

	REP(i,n){
		REP(j,n){
			ds[i][j]=pii(d[i][j],j);
			invds[j][i]=pii(d[i][j],i);
		}
		sort(ds[i],ds[i]+n);
		reverse(ds[i],ds[i]+n);
	}
	REP(i,n){
		sort(invds[i],invds[i]+n);
		reverse(invds[i],invds[i]+n);
	}

	int best=0;
	int a1,a2,a3,a4;
	REP(i,n)REP(j,n)if(i!=j && d[i][j]!=-1){
		REP(i1,4){
			int nv = ds[j][i1].second;
			if(nv==i || nv==j)continue;
			if(ds[j][i1].first==-1)continue;
			REP(i2,4){
				int nv2 = invds[i][i2].second;
				if(invds[i][i2].first==-1)continue;
				if(nv2==i || nv2==j || nv2==nv)continue;
				if(best<d[i][j]+ds[j][i1].first+invds[i][i2].first){
					best=d[i][j]+ds[j][i1].first+invds[i][i2].first;
//					if(best==17) cout<<d[i][j]<<' '<<ds[j][i1].second<<' '<<invds[i][i2].second<<endl;
					a1 = nv2;
					a2 = i;
					a3 = j;
					a4 = nv;
				}
			}
		}
	}
	cout<<a1+1<<' '<<a2+1<<' '<<a3+1<<' '<<a4+1<<' '<<endl;
	//cout<<best<<endl;
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}