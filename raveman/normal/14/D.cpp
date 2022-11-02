#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n;
vi v[222];
int u[222];
vi p;

int dfs(int v1,int v2,int par=-1){
	u[v1] = 1;
	if(v1==v2) return 0;

	REP(i,v[v1].size()){
		int nw = v[v1][i];
		if(nw==par) continue;

		int vl = dfs(nw, v2,v1);
		if(vl>=0) return vl+1;
	}

	u[v1] = 0;
	return -1;
}

void bfs(int ver){
	p.pb(ver);u[ver]=2;
	for(int i=0;i<p.size();i++){
		int w = p[i];
		REP(j,v[w].size()) if(!u[v[w][j]]){
			p.pb(v[w][j]);
			u[v[w][j]]=2;
		}
	}
}

int dfs3(int ver,int par=-1){
	int val = 0;
	REP(i,v[ver].size()){
		int nw = v[ver][i];
		if(nw==par) continue;
		if(u[nw]==2){
			val = max(val, 1 + dfs3(nw,ver));
		}
	}
	return val;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n-1){
		int x,y;
		cin>>x>>y;
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}

	int res = 0;
	REP(i,n) REP(j,n){
		CL(u,0);
		int len = dfs(i,j);
		REP(k,n) if(!u[k]){
			p.clear();
			bfs(k);
			res = max(res, len * dfs3(p.back()));

		}
	}
	cout<<res<<endl;

	
	return 0;
}