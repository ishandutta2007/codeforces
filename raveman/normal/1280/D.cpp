#pragma comment(linker, "/STACK:60777216")  

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
typedef pair<double,double>	pdd;
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
int b[3333],w[3333];
vi  v[3333];

vector<pl> r[3333];

void update(vector<pl> a, const vector<pl>& b,vector<pl>& r){
	r.clear();
	REP(i1,a.size()){
		if(a[i1].first==-1)continue;
		REP(i2,b.size()){
			while(i1+i2>=r.size())r.pb(pl(-1,0));
			if(b[i2].first==-1)continue;
			// merge
			r[i1+i2-1]=max(r[i1+i2-1],pl(a[i1].first+b[i2].first,a[i1].second+b[i2].second));
			// no merge
			r[i1+i2]=max(r[i1+i2],pl(a[i1].first+b[i2].first+(b[i2].second>0?1:0),a[i1].second));
		}
	}
}

void solve(int ver,int par=-1){
	if(!r[ver].empty())return;
	
	// leaf
	r[ver].pb(pl(-1,0));
	r[ver].pb(pl(0,w[ver]-b[ver]));
	
	
	REP(i,v[ver].size()){
		int nv = v[ver][i];
		if(nv==par)continue;
		solve(nv,ver);

		//second
		update(r[ver],r[nv],r[ver]);
	}
	while(!r[ver].empty() && r[ver].back().first==-1)r[ver].pop_back();
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>m;

		//n=3000;m=rand()%n+1;
		
		REP(i,n)v[i].clear(),r[i].clear();
		
		REP(i,n)scanf("%d",b+i);REP(i,n)scanf("%d",w+i);
		//REP(i,n)b[i]=rand()%100,w[i]=rand()%100;
		
		REP(i,n-1){
			int x,y;

			scanf("%d %d",&x,&y);x--,y--;
			//y=i+1;x=rand()%y;

			v[x].pb(y);
			v[y].pb(x);
		}
		if(n==1){
			if(w[0]>b[0]) puts("1");
			else puts("0");
		}else{
			//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
			solve(0);
			cout << r[0][m].first+(r[0][m].second>0?1:0)<<endl;
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}