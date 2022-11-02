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
vector<pii> v[111111];

bool u[111111];
int Q;

int found = -1,A,B;

void D(int ver,int last=-1){
	if(u[ver]) return;
	u[ver]=true;
	Q++;
	REP(i,v[ver].size()){
		if(v[ver][i].second != last && u[v[ver][i].first])
			found = v[ver][i].second,A = ver,B = v[ver][i].first;
		D(v[ver][i].first, v[ver][i].second);
	}
}

vector<pii> c;
vector<vi> res;
int num;
vi curr;
bool W[222222];

void dfs(int ver,int last_edge = -1){
	if(u[ver]) return;
	u[ver]=true;
	if(curr.size() || res.size() == 0 || res[res.size() -2 ].back()!=ver)
		curr.pb(ver);
	REP(i,v[ver].size())if(v[ver][i].second!=last_edge){
		int to = v[ver][i].first;
		if(!u[to]) dfs(to, v[ver][i].second),curr.pb(ver);
		if(c.size() && !W[v[ver][i].second]){
			W[v[ver][i].second]=1;
			res.pb(curr);
			curr.clear();
			//curr.pb(ver);

			num++;
			vi temp;
			temp.pb(v[ver][i].second);
			temp.pb(ver);
			temp.pb(c.back().second);
			c.pop_back();

			res.pb(temp);

			dfs(temp.back(),-1);

			curr.pb(ver);

		}
	}
}

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(pii(y,i+1));
		v[y].pb(pii(x,i+1));
	}
	if(n==1){
		puts("YES\n0\n1 1");
		return 0;
	}
	
	D(1);
	FOR(i,1,n+1)if(!u[i])D(i);
	c.clear();

	if(v[1].size()==0){
		vi t;
		t.pb(1);
		res.pb(t);

		if(found == -1) {
			int vv=-1;
			FOR(i,1,n+1) if(vv == -1 || v[i].size() > v[vv].size()) vv = i;
			if(vv!=-1 && v[vv].size() > 0) found = v[vv][0].second,A=vv,B=v[vv][0].first;
		}

		if(found != -1){
			REP(i,n+1) REP(j,v[i].size()) if(v[i][j].second == found){
				v[i].erase(v[i].begin()+j);
				break;
			}
			W[found] = true;
			t.clear();
			t.pb(found);num++;
			t.pb(A);
			t.pb(1);
			res.pb(t);
			v[1].pb(pii(A,found));
			v[A].pb(pii(1,found));
			D(A);
		}else{
			puts("NO");
			return 0;
		}
	}
	
	CL(u,0);
	D(1);
	FOR(i,1,n+1)if(!u[i])Q=0,D(i),c.pb(pii(Q,i));
	SORT(c);
	
	CL(u,0);
	dfs(1);
	res.pb(curr);
	bool good = true;
	FOR(i,1,n+1)if(!u[i]) good = false;
	if(!good){
		puts("NO");
		return 0;
	}
	puts("YES");
	cout<<num<<endl;
	REP(i,res.size()){
		if(i%2){}
		else printf("%d ",res[i].size());
		REP(j,res[i].size()){
			if(j) printf(" ");
			printf("%d",res[i][j]);
		}
		puts("");
	}
	return 0;
}