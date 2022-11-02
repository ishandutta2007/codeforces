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

vector<p3> e;

int pall[222222];
int PALL(int x){return pall[x]==x?x:pall[x]=PALL(pall[x]);}
int pnz[222222];
int PNZ(int x){return pnz[x]==x?x:pnz[x]=PNZ(pnz[x]);}

vi v[222222];

bool u[222222];

int iind[222222];

bool G[1111][1111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int xr=0;
	cin>>n>>m;
	REP(i,n)pall[i]=i,pnz[i]=i;
	REP(i,m){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		x--,y--;
		e.pb(p3(z,pii(x,y)));
		v[x].pb(y);
		v[y].pb(x);
		xr^=z;
	}
	SORT(e);

	if(n>=1000){
		// merge pall
		int mn=0;
		REP(i,n)if(v[i].size()<v[mn].size())mn=i;
		REP(i,v[mn].size())u[v[mn][i]]=1;
		int cnt=0;
		vi rem;
		REP(i,n){
			u[i]=1-u[i];
			if(u[i]){
				pall[i]=mn;
			}else rem.pb(i);
		}
		REP(i,n)cnt+=u[i];
		REP(i,n){
			int tc=0;
			REP(j,v[i].size()){
				if(u[v[i][j]])tc++;
			}
			if(tc!=cnt){
				pall[i]=mn;
			}
		}
		while(rem.size()>=1000);
		CL(iind,-1);
		REP(i,rem.size())iind[rem[i]]=i;
		REP(i,e.size()){
			int id1 = iind[e[i].second.first];
			int id2 = iind[e[i].second.second];
			if(id1!=-1 && id2!=-1){
				G[id1][id2]=G[id2][id1]=1;
			}
		}
		REP(i1,rem.size())REP(i2,i1)if(!G[i1][i2]){
			int p1 = PALL(rem[i1]);
			int p2 = PALL(rem[i2]);
			if(p1!=p2) pall[p1]=p2;
		}

		ll res=0;
		REP(i,e.size()){
			int p1 = PALL(e[i].second.first);
			int p2 = PALL(e[i].second.second);
			if(p1!=p2){
				res+=e[i].first;
				pall[p1]=p2;
			}
		}
		cout<<res<<endl;
	}else{
		REP(i,e.size()){
			int v1 = e[i].second.first;
			int v2 = e[i].second.second;
			G[v1][v2]=G[v2][v1]=1;
		}
		bool f=0;
		REP(i,n)REP(j,i)if(!G[i][j]){
			int p1 = PALL(i);
			int p2 = PALL(j);
			if(p1!=p2){
				pall[p1]=p2;
			}else f=1;
		}

		if(f){
			ll res=0;
			REP(i,e.size()){
				int p1 = PALL(e[i].second.first);
				int p2 = PALL(e[i].second.second);
				if(p1!=p2){
					res+=e[i].first;
					pall[p1]=p2;
				}
			}
			cout<<res<<endl;
		}else{
			ll res=0;
			REP(i,e.size()){
				int yo1 = PNZ(e[i].second.first);
				int yo2 = PNZ(e[i].second.second);
				int p1 = PALL(e[i].second.first);
				int p2 = PALL(e[i].second.second);

				if(yo1==yo2){
					continue;
				}

				pnz[yo1]=yo2;

				if(p1!=p2){
					res+=e[i].first;
					pall[p1]=p2;
				}else{
					if(f)continue;
					f=1;
					res+=min(e[i].first,xr);
				}
			}
			cout<<res<<endl;
		}
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}