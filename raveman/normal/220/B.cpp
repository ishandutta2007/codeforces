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

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m;
int a[111111];
map<int,int> q;
int g[111111];
vi good;
int c[100001][488];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n) scanf("%d",a+i),q[a[i]]++;
	CL(g,-1);
	for(map<int,int>::iterator it = q.begin();it!=q.end();it++){
		if(it->first <= it->second){
			g[it->first]=good.size();
			good.pb(it->first);
		}
	}

	REP(i,n){
		if(i) memcpy(c[i], c[i-1], sizeof c[i]);
		if(a[i]<=n && g[a[i]]!=-1)
			c[i][g[a[i]]]++;
	}

	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		int res = 0;
		REP(j,good.size()){
			int tres = c[y][j];
			if(x>0) tres -= c[x-1][j];
			if(tres==good[j]) res++;
		}
		printf("%d\n",res);
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}