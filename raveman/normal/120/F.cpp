#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

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

int n;
vi v[111];
int u[111];
queue<int> q;
pii dfs(int x){
	CL(u,0);
	q.push(x);
	u[x]=1;
	while(q.size()){
		int x = q.front();q.pop();
		REP(i,v[x].size()) if(u[v[x][i]]==0){
			u[v[x][i]]=u[x]+1;
			q.push(v[x][i]);
		}
	}
	int mx = 0;
	REP(i,n)if(u[i]>u[mx]) mx= i;
	return pii(mx,u[mx]);
}

int main(){
	freopen("input.txt","r",stdin);
#ifndef LocalHost
	freopen("output.txt","w",stdout);
#endif

	int tc;
	int sum=0;
	cin>>tc;
	REP(i,tc){
		cin>>n;
		REP(j,n) v[j].clear();
		REP(j,n-1){
			int x,y;
			scanf("%d %d",&x,&y);x--,y--;
			v[x].pb(y);
			v[y].pb(x);
		}
		pii x = dfs(0);
		sum += dfs(x.first).second-1;
	}
	cout<<sum<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}