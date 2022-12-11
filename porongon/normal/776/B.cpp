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

#define K 100005

bool isp[K];
int n;

int main(){
	memset(isp,1,sizeof(isp));
	FOR(i,2,K)if(isp[i])for(int j=i+i;j<K;j+=i)isp[j]=0;
	scanf("%d",&n);
	if(n<=2)puts("1");
	else puts("2");
	FOR(i,2,n+2){
		if(i>2)putchar(' ');
		printf("%d",2-isp[i]);
	}
	puts("");
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