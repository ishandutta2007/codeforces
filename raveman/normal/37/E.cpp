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

#define sz(a)			int(a.size())
#define all(a)			(a).begin(), (a).end()
#define CL(a, b)		memset(a, b, sizeof a) 
#define FOR(i, a, b)	for (int i(a); i < (b); ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(a)			sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb				push_back
#define SORT(a)			sort(all(a))

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n,m;
string s[55];
int u[55][55];

int x;

void D(int i,int j){
	if(u[i][j]) return;
	u[i][j]=true;
	FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
		int nx = i + dx;
		int ny = j + dy;
		if(nx>=0 && nx<n && ny>=0 && ny<m && s[nx][ny]==s[i][j]){
			D(nx,ny);
		}
	}
	
}
void dfs(int i,int j){
	int num=0;
	D(i,j);
	bool p = 1;
	while(p){
		p=0;
		vector<pii> v;
		REP(i,n)REP(j,m)if(u[i][j]){
			FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
				int nx = i + dx;
				int ny = j + dy;
				if(nx>=0 && nx<n && ny>=0 && ny<m && s[nx][ny]!=s[i][j] && !u[nx][ny]){
					v.pb(pii(nx,ny));
				}
			}
		}
		if(v.size()){
			num++;
			REP(i,v.size()){
				D(v[i].first,v[i].second);
				if(s[v[i].first][v[i].second]=='B') x = max(x, num);
			}
			p=1;
		}
	}
}

bool v[55][55];

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif

	cin>>n>>m;
	REP(i,n) cin>>s[i];

	int res = 1000000;

	REP(i,n)REP(j,m)if(!v[i][j]){
		CL(u,0);
		D(i,j);
		REP(i,n)REP(j,m)v[i][j]|=u[i][j];
		x = 0;
		CL(u,0);
		dfs(i,j);
		//if(s[i][j]=='B') x++;
		if(x==0 && s[i][j]=='W') x=-1;
		res =min(res,x+1);
	}

	cout<<res<<endl;

	return 0;
}