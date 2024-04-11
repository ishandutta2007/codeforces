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

#define TASKNAME "D"

typedef long long ll;
typedef long double ld;

const int INF = 2100000000;

const int MAXN = 210000;

vector<int> g[MAXN];
vector<int> c[MAXN];

struct event{
    int y;
    int x;
    bool type;
    int id;
    event(){}
    event(int y,int x,bool type,int id):y(y),x(x),type(type),id(id){};
    bool operator<(const event& a) const{
        if (x != a.x) return x < a.x;
        if (type != a.type) return type < a.type;
        return id < a.id;
    }
};

vector<event> ev;

int l[MAXN];
int r[MAXN];
int n;

int get(int a,int b){
    return min(r[a],r[b]) - max(l[a],l[b]);
}

int ans[MAXN];

int dfs(int v){
    if (ans[v] != -1)
        return ans[v];
    if (v == 1)
        return INF;
    int& ans = ::ans[v];
    ans = 0;
    for (int i = 0; i < (int)g[v].size(); i++)
        ans = max(ans, min(c[v][i],dfs(g[v][i])));
    return ans;
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

  int t;
  scanf("%d %d",&n,&t);



  n += 2;

  l[0] = l[1] = -(1<<30);
  r[0] = r[1] = (1<<30);

  for (int i = 2; i < n; i++){
    int h;
    scanf("%d %d %d",&h,&l[i],&r[i]);
    ev.pb(event(h,l[i],1,i));
    ev.pb(event(h,r[i],0,i));
  }

  sort(ev.begin(),ev.end());

  set<pair<int,int> > s;
  s.insert(mp(t,0));
  s.insert(mp(0,1));

  for (int i = 0; i < (int)ev.size(); i++){
    if (ev[i].type == 0){
        s.erase(mp(ev[i].y,ev[i].id));
    } else {
        set<pair<int,int> >::iterator iter = s.insert(mp(ev[i].y,ev[i].id)).first;
        int down = (--iter)->second;
        ++iter;
        int up = (++iter)->second;
        if (g[up].size() && g[up].back() == down){
//              cerr <<"- "<<up <<" "<<down << endl;
            g[up].pop_back();
            c[up].pop_back();
        }
//          cerr <<"+ "<<up <<" "<<ev[i].id <<" "<<get(ev[i].id,up)<<endl;
        g[up].pb(ev[i].id);
        c[up].pb(get(ev[i].id,up));
//          cerr <<"+ "<<ev[i].id <<" "<<down <<" "<<get(ev[i].id,up)<<endl;

        g[ev[i].id].pb(down);
        c[ev[i].id].pb(get(ev[i].id,down));
    }
  }

  memset(ans,-1,sizeof(ans));
  
  cout << dfs(0) << endl;      
  return 0;
}