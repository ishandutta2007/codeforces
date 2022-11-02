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
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int k,n,m;
string s[1111];
bool key[1111][1111];
vector<pii> v[1111];
char st[22];
int b[1111];
bool o[1111];
bool u[1111][1111];
vi lt[1111];
bool shit = 1;
void dfs(int guy,int ver){
	if(u[guy][ver]) return;
	u[guy][ver]=1;
	REP(i,v[ver].size())
		if(o[v[ver][i].second] || key[guy][v[ver][i].second]){
			if(!o[v[ver][i].second]){
				shit=0;
				//cout<<v[ver][i].second<<endl;
				o[v[ver][i].second]=1;
				REP(j,lt[v[ver][i].second].size())
					dfs(lt[v[ver][i].second][j] ,v[ver][i].first),dfs(lt[v[ver][i].second][j] ,ver);
			}
			dfs(guy,v[ver][i].first);
		}else lt[v[ver][i].second].pb(guy);
}

vector<pair<vector<string>, pair<vi, vi> > > solve(){
	REP(i,m) lt[i].clear();
	CL(u,false);CL(o,0);
	CL(key,false);
	REP(i,k){
		int x,y;
		scanf(" %s %d %d",st,b+i,&x);b[i]--;
		s[i]=st;
		REP(j,x) scanf("%d",&y),y--,key[i][y]=1;
	}
	REP(i,k) dfs(i,b[i]);
	
	vector<pair<vector<string>, pair<vi, vi> > > res(n);
	REP(i,k){
		REP(j,n) if(u[i][j]){
			res[j].first.pb(s[i]);
			if(res[j].second.first.size()==0)
				REP(q,n)if(u[i][q])
					res[j].second.first.pb(q);
			REP(q,m)if(key[i][q])
				res[j].second.second.pb(q);

			break;
		}
	}
	REP(i,n)
		SORT(res[i].first),SORT(res[i].second.second);
	SORT(res);
	return res;
}

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	REP(i,m){
		int x,y;
		cin>>x>>y;
		x--,y--;
		v[x].pb(pii(y,i));
		v[y].pb(pii(x,i));
	}

	vector<pair<vector<string>, pair<vi, vi> > > v1 = solve();
	vector<pair<vector<string>, pair<vi, vi> > > v2 = solve();
	if(v1==v2) puts("YES");
	else puts("NO");

	return 0;
}