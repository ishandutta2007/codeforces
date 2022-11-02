#pragma comment(linker, "/STACK:60777216")  

#include <algorithm>
#include <iostream>
#include <complex>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <ctime>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define sz(a)                   int(a.size())
#define all(a)                  (a).begin(), (a).end()
#define CL(a, b)                memset(a, b, sizeof a) 
#define FOR(i, a, b)			for (int i(a); i < (b); ++i)
#define REP(i, n)               FOR(i, 0, n)
#define UN(a)                   sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb                      push_back
#define SORT(a)                 sort(all(a))

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n,m,k;
vi v[1111111];

int cc;
bool u[1111111];

void dfs(int ver){
	if(u[ver]) return;
	u[ver]=true;cc++;
	REP(i,v[ver].size())
		dfs(v[ver][i]);
}

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif

	cin>>n>>m>>k;
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	vi c;
	REP(i,n) if(!u[i]){
		cc=0;
		dfs(i);
		c.pb(cc);
	}
	SORT(c);
	if(k==1){
		cout<<max(0,(int)c.size()-2)<<endl;
	}else{
		int num1 = 0;
		REP(i,c.size()) if(c[i]==1) num1++;
		int num2 = 0;
		REP(i,c.size()) if(c[i]>2) num2 += min(k-2, c[i] - 2);
		num1 -= num2;
		cout<<(max(0,num1)-1)/2<<endl;
	}
	return 0;
}