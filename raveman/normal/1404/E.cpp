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
typedef pair<int,pii>	p3;
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
string s[222];

vi v[222*222*2];
int now;
int u[222*222*2];

bool dfs(int v1,int v2){
	if(v1==v2){u[v1]=0; return 1;}
	if(u[v1]==now)return 0;
	u[v1]=now;
	REP(i,v[v1].size()){
		int nv = v[v1][i];
		if(dfs(nv,v2)){
			swap(v[v1][i],v[v1].back());
			v[v1].pop_back();
			v[nv].pb(v1);
			u[v1]=0;
			//cout<<v1<<' ';
			return 1;
		}
	}
	return 0;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)cin>>s[i];

	int nh=0,nv=0;
	REP(i,n)REP(j,m){
		if(s[i][j]=='#' && i+1<n && s[i+1][j]=='#'){
			v[2*n*m].pb(j*n+i);
			nh++;
		}
	}
	REP(i,n)REP(j,m){
		if(s[i][j]=='#' && j+1<m && s[i][j+1]=='#'){
			v[n*m+j*n+i].pb(2*n*m+1);
			nv++;
		}
	}
	REP(i,n)REP(j,m){
		if(s[i][j]=='#' && i+1<n && s[i+1][j]=='#'){
			if(j-1>=0){
				//t1
				if(s[i][j-1]=='#'){
					v[j*n+i].pb(n*m+(j-1)*n+i);
				}
				//t2
				if(s[i+1][j-1]=='#'){
					v[j*n+i].pb(n*m+(j-1)*n+i+1);
				}
			}
			if(j+1<m){
				//t3
				if(s[i][j+1]=='#'){
					v[j*n+i].pb(n*m+j*n+i);
				}
				//t4
				if(s[i+1][j+1]=='#'){
					v[j*n+i].pb(n*m+j*n+i+1);
				}
			}
		}
	}
	int res=0;
	REP(i,n)REP(j,m)if(s[i][j]=='#')res++;
	int flow=0;
	while(1){
		//cout<<"start :" ;
		if(dfs(2*n*m,2*n*m+1))flow++;
		else{
			now++;
			if(dfs(2*n*m,2*n*m+1))flow++;
			else break;
		}
	}
	//cout<<res<<' '<<nh<<' '<<nv<<' '<<flow<<endl;
	cout<<res+flow-nh-nv<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}