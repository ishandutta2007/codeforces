#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
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
	
int n,m;
ll G,S;
ll best = -1;

struct E{
	int x,y,a,b;
	void ccin(){
		scanf("%d %d %d %d",&x,&y,&a,&b);
		x--,y--;
		//x=rand()%n;
		//y=rand()%n;
		//a=rand()%100;
		//b=rand()%100;
	}
	E(){}
	bool operator<(const E&s){
		return a<s.a;
	}
};

E e[55555];
vector<E> v[222];
bool u[222];
vector<E> p;

bool dfs(int a,int b){
	if(a==b) return 1;
	if(u[a]) return 0;
	u[a]=1;
	REP(i,v[a].size())
		if(dfs(v[a][i].x + v[a][i].y - a, b))
			return p.pb(v[a][i]),1;
	return 0;
}

int getM(){
	int m = 0;
	REP(i,n)REP(j,v[i].size()) m  = max(m, v[i][j].b);
	return m;
}
void remove(E e){
	REP(i,n)REP(j,v[i].size()) if(v[i][j].x == e.x && v[i][j].y == e.y){
		v[i].erase(v[i].begin()+j);
		break;
	}
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

	cin>>n>>m>>G>>S;
	//n=200;
	//m=50000;
	//G=S=1;

	REP(i,m) e[i].ccin();
	sort(e,e+m);

	int num = n-1;
	REP(i,m){
		int x = e[i].x;
		int y = e[i].y;
		if(x==y) continue;
		CL(u,0);p.clear();
		if(dfs(x,y)){
			int pos = 0;
			REP(j,p.size())
				if(p[j].b > p[pos].b) 
					pos = j;
			if(p[pos].b > e[i].b){
				remove(p[pos]);				
				v[x].pb(e[i]);
				v[y].pb(e[i]);
			}
		}else{
			num --;
			v[x].pb(e[i]);
			v[y].pb(e[i]);
		}

		if(num==0){
			ll curr = G * e[i].a + S * getM();
			if(best == -1 || best>curr)
				best = curr;
		}
	}

	cout<<best<<endl;
	return 0;
}