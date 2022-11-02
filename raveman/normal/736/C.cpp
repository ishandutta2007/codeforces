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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,k;
const int mod = 1000000000+7;

vi v[111];

vi merge(vi t1, vi t2){
	vi res(201);
	REP(i1,201)REP(i2,201){
		int npos = 0;
		int d1 = i1 - 100;
		int d2 = i2 - 100;
		if(d1>d2)swap(d1,d2);
		if(d1<=0 && d2<=0) npos=min(d1,d2);
		else if(d1>=0 && d2>=0) npos=max(d1,d2);
		else {
			if(d2-1>=-d1) npos = d2;
			else npos=d1;
		}
		npos+=100;
		res[npos] = (res[npos] + t1[i1] * ll(t2[i2]))%mod;
	}
	return res;
}

vi dfs(int ver,int par=-1){
	vi r;
	bool hasany = 0;
	REP(i,v[ver].size())if(v[ver][i]!=par){
		vi t = dfs(v[ver][i],ver);
		if(hasany){
			r=merge(r,t);
		}else{
			r=t;
			hasany=1;
		}
	}
	vi res(201);
	if(!hasany){
		// 1
		res[k+100]=1;
		// 0
		res[99]=1;
	}else{
		// 0 
		REP(i,201-1)res[i]=r[i+1];
		// 1
		int add = 0;
		REP(i,201){
			int d = i - 100;
			if(k+d>=0)add=(add+r[i])%mod;
		}
		//cout<<"add "<<add<<endl;
		res[k+100]=(res[k+100]+add)%mod;
	}
	//cout<<ver<<": ";REP(i,201)if(res[i])cout<<"("<<i-100<<"*"<<res[i]<<")  ,  ";puts("");
	return res;
}

int dist[111][111];

int stupid(){
	REP(i,n)REP(j,n)dist[i][j]=n;
	REP(i,n)dist[i][i]=0;
	REP(i,n)REP(j,v[i].size())dist[i][v[i][j]]=1;
	REP(k,n)REP(i,n)REP(j,n)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	int res = 0;
	REP(i,1<<n){
		bool g = 1;
		REP(j,n){
			bool f = 0;
			REP(w,n)if(dist[j][w]<=k && (i&(1<<w)))f=1;
			if(!f)g=0;
		}
		if(g)res++;
	}
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	start:
	cin>>n>>k;
	//n=100;k=20;
	//n=rand()%10+1;
	//k=rand()%10;
	REP(i,111)v[i].clear();
	REP(i,n-1){
		int x,y;
		cin>>x>>y;
		x--,y--;
		//x=i+1;y=rand()%x;
		//x=i+1;y=rand()%x;
		//cout<<"edge " <<x<<' '<<y<<endl;
		v[x].pb(y);
		v[y].pb(x);
	}

	vi t = dfs(0);

	int res = 0;
	FOR(i,100,200)res=(res+t[i])%mod;
	cout<<res<<endl;//
	//' '<<stupid()<<endl;
	//while(res!=stupid());
	//goto start;

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}