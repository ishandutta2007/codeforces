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

bool OUTPUT_TO_FILE = 0;

int n,m,k;
vi v[111111];
bool u[111111];
int cnt;

void dfs(int ver){
	if(u[ver])return;
	u[ver]=true;cnt++;
	REP(i,v[ver].size()) dfs(v[ver][i]);
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	if(OUTPUT_TO_FILE)freopen("output.txt","w",stdout);
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
	REP(i,n)if(!u[i]){
		cnt=0;
		dfs(i);
		c.pb(cnt);
	}

	ll res = 1;
	REP(i,int(c.size())-2){
		res *= n;
		res %= k;
	}
	REP(i,c.size()){
		res *= c[i];
		res %= k;
	}
	if(c.size()==1) res = 1%k;
	cout<<res<<endl;

#ifdef LocalHost
	if(!OUTPUT_TO_FILE) cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}