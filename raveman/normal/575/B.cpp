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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

const int mod = 1000000000+7;

int n;
vector<pii> e;
vi v[111111];

int p[20][111111];
int d[111111];

int s1[111111];
int s2[111111];

void dfs(int ver,int par=-1,int depth=0){
	p[0][ver]=par;
	d[ver]=depth;
	REP(i,v[ver].size())if(v[ver][i]!=par)
		dfs(v[ver][i],ver,depth+1);
}

void dfs2(int ver,int par=-1){
	REP(i,v[ver].size())if(v[ver][i]!=par){
		dfs2(v[ver][i],ver);
		s1[ver] += s1[v[ver][i]];
		s2[ver] += s2[v[ver][i]];
	}
}


int getLCA(int p1,int p2){
	if(d[p1]>d[p2])swap(p1,p2);
	for(int j=19;j>=0;j--)if(d[p[j][p2]]>=d[p1])p2=p[j][p2];
	if(p1==p2)return p1;
	for(int j=19;j>=0;j--)
		if(p[j][p1]!=p[j][p2])p1=p[j][p1],p2=p[j][p2];
	return p[0][p1];
}

void solve(int prev,int curr){
	int lca=getLCA(prev,curr);

	s1[prev]++;
	s1[lca]--;

	//cout<<curr<<' '<<lca<<endl;
	s2[curr]++;
	s2[lca]--;
}

ll st[1111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	st[0]=1;
	FOR(i,1,1111111){
		st[i]=st[i-1]*2%mod;
	}

	cin>>n;
	REP(i,n-1){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
		if(z==1)e.pb(pii(x,y));
	}
	
	CL(p,-1);
	dfs(0,0);

	FOR(j,1,20)REP(i,n)p[j][i]=p[j-1][p[j-1][i]];

	
	int k;
	cin>>k;
	int prev=0;
	REP(i,k){
		int curr;
		scanf("%d",&curr);curr--;
		solve(prev,curr);
		prev=curr;
	}

	dfs2(0);

	ll sum = 0;
	REP(i,e.size()){
		int a = e[i].first;
		int b = e[i].second;
		// a->b
		int t = 0;
		if (d[b]>d[a]){
			t = s1[b];
		}else{
			t = s2[a];
		}

		//cout<<a<<' '<<b<<' '<<t<<endl;
		
		sum = (sum + st[t]-1)%mod;
		if(sum<0)sum+=mod;
	}
	cout<<sum<<endl;

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}