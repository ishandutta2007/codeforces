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

int n,m;
set<int> p;
int a[111];
pii g[111];

int v[102][102];

int u[102];
int now;

bool dfs(int from,int to){
	if(from==to)return true;
	if(u[from]==now)return false;
	u[from]=now;
	for(int i=n+1;i>=0;i--)if(v[from][i]){
		if(dfs(i,to)) return v[from][i]--,v[i][from]++,true;
	}
	return false;
}

int solve(int prime){
	CL(v,0);
	REP(i,n){
		int t = a[i];
		int num =0 ;
		while(t%prime==0){
			t/=prime;
			num++;
		}
		if(i%2){
			v[i][n+1]=num;
		}else{
			v[n][i]=num;
		}
	}
	REP(i,m) v[g[i].first][g[i].second]=100;

	int flow = 0;
	while(1){
		now++;
		if(dfs(n,n+1)) flow++;
		else break;
	}
	return flow;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n){
		cin>>a[i];
		int x = a[i];
		for(int j=2;j*j<=x;j++){
			if(x%j==0){
				p.insert(j);
				while(x%j==0)x/=j;
			}
		}
		if(x>1)p.insert(x);
	}
	REP(i,m){
		scanf("%d %d",&g[i].first,&g[i].second);
		g[i].first--;
		g[i].second--;
		if(g[i].first%2)swap(g[i].first,g[i].second);
	}

	int res = 0;
	for(set<int>::iterator it = p.begin();it!=p.end();it++){
		res += solve(*it);
	}
	cout<<res<<endl;

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}