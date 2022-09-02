#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "C"

typedef long long ll;
typedef long double ld;

vector<int> g[210000];
vector<int> w[210000];
vector<int> id[210000];
int n,m;

int in[210000];
int ans[210000];
set<pair<int,int> > s;

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    scanf("%d %d",&n,&m);
    for (int i = 0; i < m; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        --a,--b;
        in[a] += c;
        in[b] += c;
        g[a].pb(b);
        g[b].pb(a);
        w[a].pb(c);
        w[b].pb(c);
        id[a].pb(i+1);
        id[b].pb(-i-1);
    }

    in[0] = 0;
    in[n-1] = 2100000000;

    memset(ans,-1,sizeof(ans));

    for (int i = 0; i < n; i++){
        assert(in[i] % 2 == 0);
        s.insert(mp(in[i]/=2,i));
    }

    while (s.size() != 1){
//      cerr << in[0] <<" "<<in[1] << " "<<in[2] << endl;
        assert(s.begin()->first == 0);
        int v = s.begin()->second;
        s.erase(s.begin());
        for (int i = 0; i< (int)g[v].size(); i++){
            if (ans[abs(id[v][i])-1] == -1){
                if (id[v][i] < 0)
                    ans[abs(id[v][i])-1] = 1;
                else
                    ans[abs(id[v][i])-1] = 0;
                s.erase(mp(in[g[v][i]],g[v][i]));
                in[g[v][i]] -= w[v][i];
                s.insert(mp(in[g[v][i]],g[v][i]));
            }
        }
    }

    for (int i = 0; i < m; i++)
        printf("%d\n",ans[i]);
        

      
  return 0;
}