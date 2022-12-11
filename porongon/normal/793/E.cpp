#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

void porongueado(){puts("NO");exit(0);}

vi g[5005];
int f[5005];
int n,a,b,c,d;
vi wa,wb,wc,wd;
int ra,rb,rc,rd;
int q[5005];
vi t;
bitset<5005> ss;

void dfs(int x){
	q[x]=0;
	if(!g[x].size())q[x]++;
	for(int y:g[x])dfs(y),q[x]+=q[y];
}

void doit(int a, int& r, vi& w){
	r=a;
	bitset<5005> ss;ss.reset();
	ss[0]=1;
	while(f[r]){
		int pr=r;
		r=f[r];
		for(int y:g[r])if(y!=pr)ss|=ss<<q[y];
	}
	FORN(i,n+1)if(ss[i])w.pb(i);
}

int main(){
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);a--;b--;c--;d--;
	FOR(i,1,n){
		scanf("%d",f+i);f[i]--;
		g[f[i]].pb(i);
	}
	dfs(0);
	if(q[0]%2)porongueado();
	doit(a,ra,wa);
	doit(b,rb,wb);
	doit(c,rc,wc);
	doit(d,rd,wd);
	for(int x:g[0])if(x!=ra&&x!=rb&&x!=rc&&x!=rd)t.pb(q[x]);
	ss[0]=1;
	for(int s:t)ss|=ss<<s;
	int p=(q[0]-2)/2;
	bool r=0;
	for(int ka:wa){
		for(int kb:wb){
			int h=q[ra]-ka-1+q[rc]+kb;
			if(h<=p&&ss[p-h]){r=1;break;}
		}
		if(r)break;
	}
	if(r){
		r=0;
		for(int kc:wc){
			for(int kd:wd){
				int h=q[rc]-kc-1+q[rb]+kd;
				if(h<=p&&ss[p-h]){r=1;break;}
			}
			if(r)break;
		}
		if(r){puts("YES");return 0;}
	}
	r=0;
	for(int ka:wa){
		for(int kb:wb){
			int h=q[ra]-ka-1+q[rd]+kb;
			if(h<=p&&ss[p-h]){r=1;break;}
		}
		if(r)break;
	}
	if(r){
		r=0;
		for(int kc:wc){
			for(int kd:wd){
				int h=q[rc]-kc-1+q[ra]+kd;
				if(h<=p&&ss[p-h]){r=1;break;}
			}
			if(r)break;
		}
		if(r){puts("YES");return 0;}
	}
	puts("NO");
	return 0;
}



/*
  _____   ____  _____   ____  _   _  _____  ____  _   _
 |  __ \ / __ \|  __ \ / __ \| \ | |/ ____|/ __ \| \ | |
 | |__) | |  | | |__) | |  | |  \| | |  __| |  | |  \| |
 |  ___/| |  | |  _  /| |  | | . ` | | |_ | |  | | . ` |
 | |    | |__| | | \ \| |__| | |\  | |__| | |__| | |\  |
 |_|     \____/|_|  \_\\____/|_| \_|\_____|\____/|_| \_|

*/