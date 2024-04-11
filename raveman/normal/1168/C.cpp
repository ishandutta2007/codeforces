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

int n,q;
int a[333333];
int p[20][20];

int r[333333][20];

int id[20];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>q;
	REP(i,n)scanf("%d",a+i);
	CL(r,-1);CL(p,-1);
	for(int i=n-1;i>=0;i--){
		REP(j1,19)if(a[i]&(1<<j1)){
			r[i][j1]=i;
		}
		REP(j1,19)if(a[i]&(1<<j1)){
			REP(j2,19)if(!(a[i]&(1<<j2))){
				int v = p[max(j1,j2)][min(j1,j2)];
				if(v==-1)continue;
				if(r[i][j2]==-1 || r[i][j2]>v)r[i][j2]=v;
			}
		}
		REP(j1,19)if(r[i][j1]!=-1 && r[i][j1]!=i){
			REP(j2,19){
				if(r[r[i][j1]][j2]==-1)continue;
				if(r[i][j2]==-1) r[i][j2]=r[r[i][j1]][j2];
				else r[i][j2]=min(r[i][j2],r[r[i][j1]][j2]);;
			}
		}
		REP(j1,19)if(a[i]&(1<<j1))REP(j2,j1)if((a[i]&(1<<j2))){
			p[j1][j2]=i;
		}
	}

	REP(i,q){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		bool g = 0;
		REP(j,19)if(a[y]&(1<<j)){
			if(r[x][j]==-1)continue;
			if(r[x][j]<=y)g=1;
		}
		if(!g)puts("Fou");
		else puts("Shi");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}