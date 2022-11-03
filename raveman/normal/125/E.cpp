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

struct Edge{
	int x,y,w,id;
	Edge(){id=-1;}
	bool operator<(const Edge &s) const{
		return w<s.w;
	}
};

int n,m,k;
Edge e[111111];
int p[5555];
int P(int v){return p[v]==v?v:p[v]=P(p[v]);}
void join(int p1,int p2){p[P(p2)]=P(p1);}

vector<Edge> t[5555];
vector<Edge> v[5555];
bool         u[111111];

void add(Edge e){
	u[e.id]=true;
	t[e.x].pb(e);
	t[e.y].pb(e);
}
void remove(Edge e){
	u[e.id]=false;
	REP(TC,2){
		REP(i,t[e.x].size()) if(t[e.x][i].id == e.id){
			swap(t[e.x][i], t[e.x].back());
			t[e.x].pop_back();
			break;
		}
		swap(e.x,e.y);
	}
}

Edge d[5555];
void dfs(int ver,int par,Edge mx){
	d[ver] = mx;
	REP(i,t[ver].size()){
		int s = (t[ver][i].x==ver ? t[ver][i].y:t[ver][i].x);
		if(s!=par){
			dfs(s,ver, par!=-1 && (mx.id==-1 || mx.w < t[ver][i].w) ? t[ver][i] : mx);
		}
	}
}

int q[5555];

void dfs2(int ver,int col){
	if(ver==0 || q[ver]==col) return;
	q[ver]=col;
	REP(i,t[ver].size())
		dfs2(t[ver][i].x+t[ver][i].y-ver,col);
}

Edge mm[5555];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	REP(i,m){
		scanf("%d %d %d",&e[i].x,&e[i].y,&e[i].w);
		e[i].id = i;
		e[i].x--;
		e[i].y--;
		if(e[i].x>e[i].y) swap(e[i].x,e[i].y);
		v[e[i].x].pb(e[i]);
		v[e[i].y].pb(e[i]);
	}
	sort(e,e+m);
	REP(i,n) p[i]=i;
	int num=0;
	REP(j,m)if(P(e[j].x)!=P(e[j].y)){
		join(e[j].x,e[j].y);
		t[e[j].x].pb(e[j]);
		t[e[j].y].pb(e[j]);
		u[e[j].id]=true;
		num++;
	}
	if(num!=n-1 || v[0].size()<k){puts("-1");return 0;}
	while(t[0].size()<k){
		dfs(0,-1,Edge());
		int pos=-1,cost = -1;
		REP(i,v[0].size()) if(!u[v[0][i].id])
			if(pos==-1 || v[0][i].w - d[v[0][i].y].w < cost)
				pos = i,
				cost = v[0][i].w - d[v[0][i].y].w;
		remove(d[v[0][pos].y]);
		add(v[0][pos]);
	}
	while(t[0].size()>k){
		CL(q,-1);
		REP(i,t[0].size()){
			dfs2(t[0][i].y, i);
			mm[i].id=-1;
		}
		REP(i,m) if(e[i].x)
			if(q[e[i].x]!=q[e[i].y]){
				if(mm[q[e[i].x]].id==-1 || mm[q[e[i].x]].w > e[i].w)
					mm[q[e[i].x]] = e[i];
				if(mm[q[e[i].y]].id==-1 || mm[q[e[i].y]].w > e[i].w)
					mm[q[e[i].y]] = e[i];
			}
		int pos=-1;
		REP(i,t[0].size())if(mm[i].id!=-1)
			if(pos==-1 || mm[pos].w - t[0][pos].w > mm[i].w - t[0][i].w)
				pos=i;
		if(pos==-1){
			puts("-1");
			return 0;
		}
		remove(t[0][pos]);
		add(mm[pos]);
	}
	cout<<n-1<<endl;
	bool f = 1;
	REP(i,m)if(u[i]){
		if(!f) printf(" ");
		f=0;
		printf("%d",i+1);
	}
	puts("");
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}