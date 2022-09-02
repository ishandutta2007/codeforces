#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 110000;

int len;
ll ans;

struct mymap{
    map<int,int> m;
    int add;

    void merge(mymap& a){
        if (a.m.size() > m.size()){
            swap(a.add,add);
            m.swap(a.m);
        }

        for (map<int,int>::iterator iter = a.m.begin(); iter != a.m.end(); ++iter){
            int val = iter->second;
            int dh = iter->first + a.add;
            int nh = len - dh;
            nh -= add;
            if (m.find(nh) != m.end())
                ans += val * 1LL * m[nh];
        }

        for (map<int,int>::iterator iter = a.m.begin(); iter != a.m.end(); ++iter){
            int val = iter->second;
            int dh = iter->first + a.add;
            dh -= add;
            if (m.find(dh) == m.end())
                m[dh] = 0;
            m[dh] += val;
        }
    }

};

mymap res[110000];

vector<int> g[MAXN];
int n;

void dfs(int v,int p){
    res[v].m[0] = 1;
    res[v].add = 0;

    for (int i = 0; i < (int)g[v].size(); i++){
        int to = g[v][i];
        if (to == p)
            continue;
        dfs(to,v);
        res[to].add++;
        res[v].merge(res[to]);
    }
}




int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  scanf("%d %d",&n,&len);

  for (int i = 0; i < n-1; i++){
    int a,b;
    scanf("%d %d",&a,&b);
    --a,--b;
    g[a].pb(b);
    g[b].pb(a);
  }

  dfs(0,-1);

  cout << ans << endl;

  return 0;
}