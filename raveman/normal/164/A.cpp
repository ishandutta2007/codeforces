#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int n,m;
int a[111111];
vi  v[111111];
vi vt[111111];
bool final[111111];
bool u[111111];
bool cool[111111];

void dfs2(int ver){
	if(u[ver]) return;
	u[ver]=true;
	cool[ver]=true;
	REP(i,vt[ver].size()){
		int nv = vt[ver][i];
		if(a[nv]!=1)
				dfs2(nv);
	}
}


void dfs(int ver){
	if(u[ver]) return;
	u[ver]=true;
	REP(i,v[ver].size()){
		int nv = v[ver][i];
		if(a[nv]!=1) dfs(nv);
		if(a[ver]==1 && cool[nv]) 
			final[ver]=1;
	}
	if(cool[ver]) final[ver]=true;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n) scanf("%d",a+i);
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		vt[y].pb(x);
	}
	REP(i,n) if(a[i]==2) dfs2(i);
	CL(u,0);
	REP(i,n) if(a[i]==1) dfs(i);
	REP(i,n) printf("%d\n",(final[i]?1:0));
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}