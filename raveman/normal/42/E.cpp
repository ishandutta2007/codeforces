#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

typedef pair<int,pii> p3;

int n,m,x,y,z;
vector<p3> v;
vector<pii>      s[111111];

int q[111111][22];
int Q[111111][22];
int d[111111];

void dfs(int ver,int par=-1){
	REP(i,s[ver].size())if(s[ver][i].first!=par){
		q[s[ver][i].first][0] = s[ver][i].second;
		Q[s[ver][i].first][0] = ver;
		d[s[ver][i].first] = d[ver] + 1;
		dfs(s[ver][i].first,ver);
	}
}

int solve(int x,int y){
	if(d[x] > d[y]) swap(x,y);
	int res = 0;
	for(int i=20;i>=0;i--)if(d[x] <= d[y] -(1<<i)){
		res = max(res, q[y][i]);
		y = Q[y][i];
	}
	if(x!=y) for(int i=20;i>=0;i--)if(d[x]>=(1<<i))
		while(i==0 || Q[x][i] != Q[y][i]){
			res = max(res, q[x][i]);
			res = max(res, q[y][i]);
			x = Q[x][i];
			y = Q[y][i];
			if(x==y)break;
		}
	return res;
}

int p[111111];
int c[111111];
int P(int v){return v==p[v] ? v : p[v] = P(p[v]);}

void join(int p1,int p2){
	c[P(p2)]+=c[P(p1)];
	p[P(p1)]=P(p2);
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		scanf("%d %d %d",&x,&y,&z);
		x--,y--;
		v.pb(p3(z,pii(x,y)));
	}
	SORT(v);
	REP(i,n) p[i]=i,c[i]=1;
	ll res = 0;
	REP(i,v.size()) if(P(v[i].second.first)!=P(v[i].second.second)){
		res += v[i].first;
		s[v[i].second.first].pb(pii(v[i].second.second,v[i].first));
		s[v[i].second.second].pb(pii(v[i].second.first,v[i].first));
		join(v[i].second.first,v[i].second.second);
	}

	if(c[P(0)]==n){
		dfs(0);
		for(int step=1;step<=20;step++) REP(i,n) if(d[i] >= (1<<step)){
			q[i][step] = max(q[i][step-1], q[Q[i][step-1]][step-1]);
			Q[i][step] = Q[Q[i][step-1]][step-1];
		}
	}

	int q;
	cin>>q;
	REP(i,q){
		scanf("%d %d",&x,&y);
		x--,y--;

		if(P(x)!=P(y) && c[P(x)]+c[P(y)]!=n || P(x)==P(y) && c[P(x)]!=n) puts("-1");
		else if(P(x)!=P(y)) printf("%I64d\n",res);
		else printf("%I64d\n",res - solve(x,y));
	}
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;

#endif
	return 0;
}