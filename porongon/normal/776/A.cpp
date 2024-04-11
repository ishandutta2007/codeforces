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

string s,t;
int n;

int main(){
	cin>>s>>t>>n;
	cout<<s<<' '<<t<<'\n';
	FORN(i,n){
		string s2,t2;
		cin>>s2>>t2;
		if(s==s2)s=t2;
		else t=t2;
		cout<<s<<' '<<t<<'\n';
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