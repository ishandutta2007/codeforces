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

int n,m;
vector<int> c[2];
int comp[MAXN];
vector<int> g[MAXN];
int ans[MAXN];          
int color;

void dfs(int v,int c){
    if (comp[v] != -1)
        return;
    ::c[c].pb(v);
    comp[v] = c;
    for (int i = 0; i < (int)g[v].size(); i++)
        dfs(g[v][i],1-c);
}


void print(){

   for (int i = 0; i < (int)c[0].size(); i++)
    if (ans[c[0][i]] != -1){
        swap(c[0][i],c[0].back());
        c[0].pop_back();
        i--;
    }

   for (int i = 0; i < (int)c[1].size(); i++)
    if (ans[c[1][i]] != -1){
        swap(c[1][i],c[1].back());
        c[1].pop_back();
        i--;
    }

   assert(c[0].size()%3 == 0);
   assert(c[1].size()%3 == 0);

   for (int i = 0; i < (int)c[0].size(); i+=3)
      ans[c[0][i]] = ans[c[0][i+1]] = ans[c[0][i+2]] = color++;
   for (int i = 0; i < (int)c[1].size(); i+=3)
       ans[c[1][i]] = ans[c[1][i+1]] = ans[c[1][i+2]] = color++;
   printf("YES\n");
   for (int i = 0; i < n; i++)
      printf("%d ",ans[i]);
   printf("\n");

   exit(0);
}

void solve(int v){
    sort(g[v].begin(),g[v].end());
    int v1;
    v1 = -1;
    vector<int>& c = ::c[1-comp[v]];
    for (int i = 0; i < (int)c.size(); i++)
        if (!binary_search(g[v].begin(),g[v].end(),c[i])){
            if (v1 == -1)
                v1 = c[i];
            else {
                ans[v] = ans[v1] = ans[c[i]] = color++;
                return;
            }
        }
}

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  scanf("%d %d",&n,&m);
  color = 1;

  for (int i = 0; i < m; i++){
    int a,b;
    scanf("%d %d",&a,&b);
    --a,--b;
    g[a].pb(b);
    g[b].pb(a);
  }

  memset(comp,-1,sizeof(comp));
  memset(ans,-1,sizeof(ans));

  for (int i = 0; i < n; i++)
    if (comp[i] == -1)
        dfs(i,0);

  if (c[0].size() % 3 == 0)
     print();
  

  if (c[0].size() % 3 == 2){
    for (int i = 0; i < n; i++)
        comp[i] = 1 - comp[i];
    c[0].swap(c[1]);
  }


  for (int i = 0; i < (int)c[0].size(); i++)
    if ((int)g[c[0][i]].size() < (int)c[1].size()-1){
       solve(c[0][i]);
       print();
    }

  int v1;
  v1 = -1;

  for (int i = 0; i < (int)c[1].size(); i++)
    if ((int)g[c[1][i]].size() < (int)c[0].size()-1){
        if (v1 == -1)
            v1 = c[1][i];
        else {
            solve(v1);
            solve(c[1][i]);
            print();
        }
    }
       

  printf("NO\n");
  return 0;
}