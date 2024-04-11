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

int n;
vi v[5555];
int u[5555];
int now;
bool g[5555];

int dfs(int ver,int par){
	if(u[ver]==now) return 0;
	u[ver] = now;
	int res = 1;
	REP(i,v[ver].size()) if(v[ver][i]!=par)
		res += dfs(v[ver][i], ver);
	return res;
}

int CANT;
int dfs2(int ver){
	if(u[ver]==now) return 0;
	u[ver] = now;
	int res = 1;
	REP(i,v[ver].size()) if(v[ver][i]!=CANT)
		res += dfs2(v[ver][i]);
	return res;
}

bool z[5555];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif

	cin>>n;
//	n=5000;
	REP(i,n-1){
		int a,b;
		scanf("%d %d",&a,&b);
	//	a=1;
		//b=i+2;
		a--,b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	REP(i,n)REP(j,v[i].size()){
		now++;
		int c = dfs(i,v[i][j]);
		g[c]=true;
		g[c-1]=true;
	}
	REP(i,n){
		CANT = i;
		now++;
		vi w;
		REP(j,n)if(i!=j && u[j]!=now)
			w.pb(dfs2(j));
		CL(z,0);
		z[0]=1;
		REP(ww,w.size()) for(int j=n;j>=0;j--)if(z[j])
			z[j+w[ww]]=true;
		REP(j,n+1)if(z[j]) g[j]=1;
	}
	int num=0;
	REP(i,n+1) if(i && n-1-i>0 && g[i]) num++;
	cout<<num<<endl;
	REP(i,n+1) if(i && n-1-i>0 && g[i]) 
		cout<<i<<' '<<n-1-i<<endl;
	
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}