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

char t[1<<20];
string s[1<<20];
int l[1<<20];
vector<string> r[1<<20];
int d[1<<20];
int n;
stack<int> st;

int main(){
	scanf("%s",t);
	int i=0;
	while(1){
		int j=i;
		while(t[j]!=','){
			s[n].pb(t[j]);
			j++;
		}
		j++;
		while(t[j]&&t[j]!=','){
			l[n]*=10;
			l[n]+=t[j]-'0';
			j++;
		}
		n++;
		if(!t[j])break;
		i=j+1;
	}
//	FORN(i,n)printf("%s %d\n",s[i].c_str(),l[i]);
	FORN(i,n){
		while(!st.empty()&&!l[st.top()])st.pop();
		d[i]=st.empty()?0:d[st.top()]+1;
		r[d[i]].pb(s[i]);
		if(!st.empty())l[st.top()]--;
		st.push(i);
	}
	int d=0;
	while(!r[d].empty())d++;
	printf("%d\n",d);
	FORN(i,d){
		FORN(j,r[i].size()){
			if(j)putchar(' ');
			printf("%s",r[i][j].c_str());
		}
		puts("");
	}
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