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

#define MAXN 200005

bool truth[MAXN]; // truth[cmp[i]]=value of variable i (2SAT)
int nvar;int neg(int x){return x>=nvar?x-nvar:x+nvar;} // (2SAT)
vi g[MAXN];
int nn,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	FORN(_,g[u].size()){
		int v=g[u][_];
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x;
		do{x=st.top();st.pop();cmp[x]=qcmp;}while(x!=u);
		truth[qcmp]=(cmp[neg(u)]<0); // (2SAT)
		qcmp++;
	}
}
void scc(){
	memset(idx,0,sizeof(idx));qidx=0;
	memset(cmp,-1,sizeof(cmp));qcmp=0;
	FORN(i,nn)if(!idx[i])tjn(i);
}
#define addor(a, b) (g[neg(a)].pb(b), g[neg(b)].pb(a))
void init_2sat(int _nvar){nvar=_nvar;nn=2*nvar;} // call beFOR addor!
bool satisf(){
	scc();
	FORN(i,nvar)if(cmp[i]==cmp[neg(i)])return 0;
	return 1;
}

int n,m;
int r[100005];
vi w[100005];

int main(){
	scanf("%d%d",&n,&m);
	init_2sat(m);
	FORN(i,n)scanf("%d",r+i);
	FORN(i,m){
		int k;
		scanf("%d",&k);
		while(k--){
			int x;
			scanf("%d",&x);x--;
			w[x].pb(i);
		}
	}
	FORN(i,n){
		int a=w[i][0],b=w[i][1];
		if(!r[i]){
			addor(a,b);
			addor(neg(a),neg(b));
		}
		else {
			addor(a,neg(b));
			addor(neg(a),b);
		}
	}
	puts(satisf()?"YES":"NO");
	return 0;
}


/*
  _____   ____  _____   ____  _   _  _____  ____  _   _
 |  __ \ / __ \|  __ \ / __ \| \ | |/ ____|/ __ \| \ | |
 | |__) | |  | | |__) | |  | |  \| | |  __| |  | |  \| |
 |  ___/| |  | |  _  /| |  | | . ` | | |_ | |  | | . ` |
 | |    | |__| | | \ \| |__| | |\  | |__| | |__| | |\  |
 |_|     \____/|_|  \_\\____/|_| \_|\_____|\____/|_| \_|

         ..MMM
         M::::~:M
      M.M:~,,,,,~.M
     M:,~~,,,,,,,.:O.
   .M.,..,,,,,,,,,,..?
    .,,..,,,,,,,,,,,,...
   M,,,,,,,,,,,,,,,,,.7
   M,,,,,~,,,,,,,,,,,~I
   M,,,,,,,:~.=~~,,=?I=.
   ..~,,,,??:::::::::..
     MM.?,~:::::::::,.
      .::::::::::::::M
      .M:::::::::::::=:.
      .M~::::::::::::::
        ~:::::::::::::~:,
        :~:::::::::::~~~~O
        M~:::::::::~:~:~~=O
         .~:::::~~~~~~~:~~~:
         M~:::::~~~~~:::::~~,.
         .?~::,~~:~~::::::~~~~8
          .:::~~~~~~::::~~~~~~~:
           M~,~~~~,:~:~~~~~:~~~~~O
           .M~~~~::::=::~~::::::,~~O,
             Z:~:::::~~~:::::::::::~?,
             :I~~,:::~~~~::::~~::::~:=N
               Z::::::~~,~::,~:~:::::~,:,Z:
                O:,:::~~~,:~,::,:::~~~~::~~:.
                 O:::::::~~~~~::::~~~:~~~~~~~~==...
                  $=::::::~~:::::~~~~=~:~~~~~====++M.
                   :?::::::::::,~~~~~~~~==~~~======+M
                    ,Z+~~:::~~~=~~~=~~:~=~~~~========M .
                      ,Z=::~~~~~~~:~~~~~~~~~~=========M
                        :O=:::~::::~~~~~~~~~~~=========.
                        ..+:,:N::::~~~~~~~~~~~========+?
                        .,:,M=M::::~~~~~=~~~~~~========M
                        D::::MM::::~~~~~~~~~~~~~~======$
                      . .::::,M:::::~~~~~=~~~~~~~~~~~=,
                      .M::::::M:::::::~~~~~=~~~~~~~~~=M,
                      .::::=::,~::::::~~~~~~=~~~~~~~~M
                     .M~:::=::~M::::::::~~~~~~~~=~~~D.
                     .I::::~::::Z:::::::::~~~~~~~~=M..
                      M,:::::::::8,::::::::::::~~.?..
                      .~::::::=::::.M,::::::::,M...
                      .M~::::::::::::::,~NM7....
                      . M=~::::::::::~~M.
                        ..M~~~::::~~,Z..
                           ..M7,=MD..
*/