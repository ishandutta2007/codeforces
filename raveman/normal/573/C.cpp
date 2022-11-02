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

bool good;
vi v[111111];

int d_isline[111111];

bool isline(int ver, int par=-1){
	if(d_isline[ver]!=-1)return d_isline[ver];
	int num=0;
	REP(i,v[ver].size())if(v[ver][i]!=par){
		num++;
		if(!isline(v[ver][i],ver)){
			return d_isline[ver]=0;
		}
	}
	return d_isline[ver]=(num<=1?1:0);
}


bool dfs2(int ver, int par){
	if(isline(ver,par)) return true;
	int num=0;
	REP(i,v[ver].size())if(v[ver][i]!=par){
		if(!isline(v[ver][i],ver)) return false;
		num++;
	}
	return num<=2;
}

bool dfs1(int ver, int par){
	//cout<<ver<<' '<<par<<endl;
	vi t;
	REP(i,v[ver].size())if(v[ver][i]!=par){
		if (dfs2(v[ver][i],ver)) continue;
		t.pb(v[ver][i]);
	}
	//cout<<t.size()<<' '<<t[0]<<endl;
	if(t.empty()) return true;
	if(t.size()>=2) return false;
	return dfs1(t[0],ver);
}


bool dfs05(int ver,int par){
	vi t;
	int numlines=0;
	REP(i,v[ver].size()) if(v[ver][i]!=par){
		if(!isline(v[ver][i],ver)) t.pb(v[ver][i]);
		else numlines++;
	}
	if(t.empty()) return true;
	else if(t.size()==1){
		return dfs1(t[0],ver);
	}else if(t.size()==2){
		return dfs1(t[0],ver)&dfs1(t[1],ver);
	}else {
		int num=0;
		REP(i,t.size()){
			if(dfs2(t[i],ver)) continue;			
			if(!dfs1(t[i],ver))return false;
			num++;
		}
		return num<=2;
	}
	return false;
}

bool dfs0(int ver,int par){
	vi t;
	int numlines=0;
	REP(i,v[ver].size()) if(v[ver][i]!=par){
		if(!isline(v[ver][i],ver)) t.pb(v[ver][i]);
		else numlines++;
	}
	//cout<<t.size()<<' '<<numlines<<endl;
	if(t.empty()) return true;
	else if(t.size()==1){
		if(numlines<=1) return dfs0(t[0],ver);
		if(numlines==2) return dfs05(t[0],ver);
		return dfs1(t[0],ver);
	}else if(t.size()==2){
		return dfs1(t[0],ver)&dfs1(t[1],ver);
	}else {
		int num=0;
		REP(i,t.size()){
			if(dfs2(t[i],ver)) continue;			
			if(!dfs1(t[i],ver))return false;
			num++;
		}
		return num<=2;
	}
	return false;
}

int pr[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	CL(d_isline,-1);
	int n;
	cin>>n;
	REP(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}	
	bool good=1;
	REP(i,n)if(v[i].size()>=3){
		good=dfs0(i,-1);
		break;
	}
	puts(good?"Yes":"No");
	

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}