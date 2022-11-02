#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
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
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

vector<pii> v[1111];
int dfs(int ver,int par,int cost){
	if(ver==1) return cost;
	REP(i,2)
		if(v[ver][i].first!=par)
			return dfs(v[ver][i].first, ver, cost+v[ver][i].second);
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

	int n;
	cin>>n;
	REP(i,n){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].pb(pii(y,0));
		v[y].pb(pii(x,z));
	}
	int c1 = dfs(v[1][1].first, 1,v[1][1].second);
	int c2 = dfs(v[1][0].first, 1, v[1][0].second);
	int c = min(c1,c2);
	cout<<c<<endl;

	return 0;
}