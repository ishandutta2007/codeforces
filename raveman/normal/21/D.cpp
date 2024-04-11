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

int n,m;
vi v[22];
int d[22][22];
int s[22];
bool u[22];
void dfs(int ver){
	u[ver]=1;
	REP(i,v[ver].size())
		if(!u[v[ver][i]])
			dfs(v[ver][i]);
}

int r[1<<15];
priority_queue<pii> q;

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif


	cin>>n>>m;
	REP(i,n)REP(j,n)d[i][j]=-1;
	int res = 0;
	REP(i,m){
		int x,y,z;
		cin>>x>>y>>z;
		res+=z;
		x--,y--;
		if(d[x][y]==-1 || d[x][y]>z) d[x][y]=z;
		v[x].pb(y);
		v[y].pb(x);
		s[x]++,s[y]++;
	}
	dfs(0);
	REP(i,n)if(s[i] && !u[i]){
		puts("-1");
		return 0;
	}
	CL(r,-1);
	int mask=0;
	REP(i,n)if(s[i]%2) mask|=(1<<i);
	q.push(pii(0,mask));
	r[mask]=0;
	while(!q.empty()){
		pii curr = q.top();q.pop();
		mask = curr.second;
		int cost = -curr.first;
		if(r[mask]!=cost) continue;
		REP(i,n) REP(j,n)if(d[i][j]!=-1){
			int nmask=mask^(1<<i)^(1<<j);
			if(r[nmask]==-1 || r[nmask]>cost+d[i][j])
				r[nmask]=cost+d[i][j],q.push(pii(-r[nmask],nmask));
		}
	}
	cout<<res+r[0]<<endl;
	return 0;
}