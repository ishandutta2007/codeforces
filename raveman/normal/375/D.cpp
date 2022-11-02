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
int c[111111];
vi  v[111111];
int a[111111];
int b[111111];
int r[111111];
vi  p[111111];

void solve(int ver,int par,map<int,int>& c_to_n,map<int,int>& n_to_c){
	map<int,int> c_to_n_child;
	map<int,int> n_to_c_child;
	REP(i,v[ver].size()) if(v[ver][i]!=par){
		c_to_n_child.clear();
		n_to_c_child.clear();
		solve(v[ver][i],ver,c_to_n_child,n_to_c_child);
		if(c_to_n_child.size() > c_to_n.size()) {
			swap(c_to_n, c_to_n_child);
			swap(n_to_c, n_to_c_child);
		}
		for(map<int,int>::iterator it = c_to_n_child.begin();it!=c_to_n_child.end();++it){
			int x = c_to_n[it->first];
			if (x>0){
				if((--n_to_c[x])==0)n_to_c.erase(x);
			}
			n_to_c[c_to_n[it->first] += it->second]++;				
		}
	}
	int x = c_to_n[c[ver]];
	c_to_n[c[ver]]++;
	if(x>0){
		if((--n_to_c[x])==0) n_to_c.erase(x);

	}
	n_to_c[x+1]++;
	REP(i,p[ver].size()){
		map<int,int>::iterator it = n_to_c.lower_bound(b[p[ver][i]]);
		int sum = 0;
		while(it!=n_to_c.end()){
			sum+=it->second;
			++it;
		}
		r[p[ver][i]]=sum;
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)scanf("%d",c+i);
	REP(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x-1].pb(y-1);
		v[y-1].pb(x-1);
	}
	REP(i,m)scanf("%d %d",a+i,b+i),p[a[i]-1].pb(i);
	map<int,int> c_to_n,n_to_c;
	solve(0,-1,c_to_n,n_to_c);
	REP(i,m)printf("%d\n",r[i]);

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}