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

int  a[1111][1111];
int rc[1111*1111];
int NUM;
int COL[1111*1111];
bool u[1111][1111];
string s[1111];
int n,m;
vi v[1001*1001];
int c;
vi curr;

void dfs(int x,int y){
	if(u[x][y]) return;
	u[x][y]=1;
	curr.pb(x*m+y);
	c++;
	FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
		int nx = x + dx;
		int ny = y + dy;
		if(nx>=0 && ny>=0 && nx<n && ny<m && s[nx][ny]=='.' && !u[nx][ny]){
			v[x*m+y].pb(nx*m+ny);
			v[nx*m+ny].pb(x*m+y);
			dfs(nx,ny);
		}
	}
}


int dfs2(int x,int y){
	if(u[x][y]) return 0;
	u[x][y]=1;
	int res = 0;
	FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
		int nx = x + dx;
		int ny = y + dy;
		if(nx>=0 && ny>=0 && nx<n && ny<m && s[nx][ny]=='.'){
			if(a[nx][ny] == a[x][y]) res |= dfs2(nx,ny);
			else res |= 1<<rc[a[nx][ny]];
		}
	}
	return res;
}

bool go(int ver,int prev=-1){
	int x = ver/m;
	int y = ver%m;
	vector<bool> w;
	vi q;
	REP(i,v[ver].size()) if(v[ver][i]!=prev)
		w.pb(go(v[ver][i],ver)),
		q.pb(v[ver][i]);

	int num = 0;
	REP(i,w.size()) if(w[i]) num++;
	
	if(num==0){
		return 1;
	}

	NUM++;
	a[x][y]=NUM;
	COL[NUM]++;
	REP(i,w.size()) if(w[i]){
		a[q[i]/m][q[i]%m]=NUM;
		COL[NUM]++;
	}

	return 0;
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	getline(cin,s[0]);
	REP(i,n) getline(cin,s[i]);
	REP(i,n)REP(j,m)if(s[i][j]=='.' && !u[i][j]){
		c=0;
		curr.clear();
		dfs(i,j);
		if(c==1){
			puts("-1");
			return 0;
		}
		if(go(i*m+j)){
			FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
				if(a[i][j]) break;
				int nx = i + dx;
				int ny = j + dy;
				if(nx>=0 && ny>=0 && nx<n && ny<m && s[nx][ny]=='.' && COL[a[nx][ny]] < 5){
					a[i][j] = a[nx][ny];
					COL[a[i][j]]++;
					break;
				}
			}
		}
	}
	CL(u,0);
	REP(i,n)REP(j,m)if(a[i][j] && rc[a[i][j]]==0){
		int mask = dfs2(i,j);
		for(rc[a[i][j]]=1;;rc[a[i][j]]++){
			if(!(mask&(1<<rc[a[i][j]]))) break;
		}
	}
	REP(i,n){
		REP(j,m) if(s[i][j]=='.')
			s[i][j]=char('0'+rc[a[i][j]]-1);
		printf("%s\n",s[i].c_str());
	}
	return 0;
}