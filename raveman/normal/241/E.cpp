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

int n,m;
int x[5555];
int y[5555];
int c[5555];
vi v[1111],vt[1111];

int r[1111];
bool v1[1111],v2[1111];

void dfs2(int ver){
	if(v2[ver]) return;
	v2[ver] = 1;
	REP(i,v[ver].size()) dfs2(x[v[ver][i]]);
}

void dfs1(int ver){
	if(v1[ver]) return;
	v1[ver] = 1;
	REP(i,vt[ver].size()) dfs1(y[vt[ver][i]]);
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		scanf("%d %d",&x[i],&y[i]);
		x[i]--,y[i]--;
		c[i]=1;
		v[y[i]].pb(i);
		vt[x[i]].pb(i);
	}
	REP(i,n)r[i]=1e6;
	r[0]=0;

	dfs1(0);
	dfs2(n-1);

	//x[i] -> y[i]

	//r[y[i]]<=r[x[i]]+2
	//r[x[i]]<=r[y[i]]-1

	REP(i,n)REP(j,m)if(v1[x[j]] && v2[y[j]])
		r[y[j]]=min(r[y[j]],r[x[j]]+2),
		r[x[j]]=min(r[x[j]],r[y[j]]-1);

	//REP(i,n) cout<<i+1<<"  "<<r[i]<<endl;

	REP(i,m)if(v1[x[i]] && v2[y[i]]){
		int d = r[y[i]]-r[x[i]];
		//cout<<d<<endl;
		if(d!=1 && d!=2){
			puts("No");
			return 0;
		}
	}

	puts("Yes");
	REP(i,m) if(!v1[x[i]] || !v2[y[i]]) cout<<1<<endl; else cout<<r[y[i]]-r[x[i]]<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}