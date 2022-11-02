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
#include<unordered_map>
#include<unordered_set>

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
vi v[1111];
bool u[1111];
int p[1111];

void dfs(int ver,int par=-1){
	p[ver]=par;
	REP(i,v[ver].size())
		if(v[ver][i]!=par) dfs(v[ver][i],ver);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		REP(i,n)v[i].clear();
		REP(i,n-1){
			int x,y;
			scanf("%d %d",&x,&y);
			x--,y--;
			v[x].pb(y);
			v[y].pb(x);
		}
		CL(u,0);
		int k1,k2,tmp;
		cin>>k1;
		REP(i,k1){
			scanf("%d",&tmp),tmp--,u[tmp]=1;
			if(i==0)dfs(tmp);
		}
		cin>>k2;
		int res = -1;
		int lookfor=-1;
		int z;
		vi tmpa;
		REP(i,k2){
			scanf("%d",&tmp);
			tmp--;
			tmpa.pb(tmp);
		}
		REP(i,k2){
			tmp=tmpa[i];
			if(res==-1&&tmp==lookfor)res=z;
			if(i==0){
				cout<<"B "<<tmp+1<<endl;
				cout.flush();
				int my;
				cin>>my;
				my--;
				if(u[my]) res=my+1;
				else{
					while(!u[my])my=p[my];
					z=my+1;
					cout<<"A "<<my+1<<endl;
					cout.flush();
					cin>>lookfor;
					lookfor--;
				}
			}
		}
		cout<<"C "<<res<<endl;
		cout.flush();
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}