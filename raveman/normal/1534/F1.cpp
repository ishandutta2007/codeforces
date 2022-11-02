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

string s[444444];
vi     v[444444];
int n,m;
int    c[444444];
pii cmp[444444];

bool cu[444444];
vi cg[444444];
vi cgr[444444];
vi o,cc;
int cid;
int CID[444444];
int hinc[444444];

void dfs1(int v){
	cu[v]=1;
	REP(i,cg[v].size())if(!cu[cg[v][i]])dfs1(cg[v][i]);
	o.pb(v);
}
void dfs2(int v){
	cu[v]=1;
	cc.pb(v);
	CID[v]=cid;
	REP(i,cgr[v].size()){
		if(!cu[cgr[v][i]])dfs2(cgr[v][i]);
	}
}

int now;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	getline(cin,s[0]);
	REP(i,n)getline(cin,s[i]);
	REP(i,n)v[i]=vi(m,-1);
	now=-1;
	REP(i,n)REP(j,m)if(s[i][j]=='#' && v[i][j]==-1){
		now++;
		cmp[now]=pii(i,j);
		v[i][j]=now;
	}
	CL(c,-1);
	//REP(i,n)REP(j,m)if(c[j]==-1 && s[i][j]=='#')c[j]=i;
	int res=0;
	REP(i,now+1){
		pii x = cmp[i];
		if(c[x.second]!=-1 && c[x.second]!=x.first){
			cg[v[c[x.second]][x.second]].pb(i);
		}

		FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
			int nx = x.first+dx;
			int ny = x.second+dy;
			if(nx>=0 && ny>=0 && nx<n && ny<m){
				if(v[nx][ny]!=-1){
					cg[i].pb(v[nx][ny]);
				}
			}
		}
		
		if(x.second>0){
			if(c[x.second-1]!=-1){
				if(c[x.second-1]<x.first) {
					cg[v[c[x.second-1]][x.second-1]].pb(i);
				}
			}
		}
		if(x.second+1<m){
			if(c[x.second+1]!=-1){
				if(c[x.second+1]<x.first) {
					cg[v[c[x.second+1]][x.second+1]].pb(i);
				}
			}
		}
		c[x.second]=x.first;
	}
	if(0)REP(i,now+1){
		cout<<i<<": ";
		cout<<cmp[i].first<<','<<cmp[i].second<<": ";
		REP(j,cg[i].size())cout<<cg[i][j]<<" ";puts("");
	}

	REP(i,now+1)REP(j,cg[i].size())cgr[cg[i][j]].pb(i);

	REP(i,now+1)if(!cu[i])dfs1(i);
	CL(cu,0);
	reverse(o.begin(),o.end());
	cid=-1;
	REP(i,o.size())if(!cu[o[i]]){
		cc.clear();
		cid++;
		dfs2(o[i]);
	}
	REP(i,now+1)REP(j,cg[i].size())if(CID[i]!=CID[cg[i][j]])hinc[CID[cg[i][j]]]=1;

	REP(i,cid+1)if(!hinc[i])res++;

	cout<<res<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}