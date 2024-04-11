#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <queue>
#include <memory.h>
#include <stack>
#include <deque>

#define mp make_pair
#define pb push_back

#define taskname "A"

#ifdef __WIN32
  #define LLD "%I64d"
#else
  #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;        

vector<int> g[110]; 
int num[100];

int f[110],s[110],c[110];

void dfs(int a,int b,int st){
  if (a==st && b!=-1)
    return;
  static int counter=0;
  num[a]=counter++;
  for (int i=0;i<g[a].size();i++)
    if (g[a][i]!=b){
      dfs(g[a][i],a,st);
      break;
    }
}




int main(){
#ifdef LOCAL
  freopen(taskname".in","r",stdin);
  freopen(taskname".out","w",stdout);
#endif
  memset(f,-1,sizeof(f));
  memset(s,-1,sizeof(s));

  int n;
  scanf("%d",&n);
  for (int i=0;i<n;i++)
    {
      int a,b,C;
      scanf("%d %d %d",&a,&b,&C);
      --a;--b;
      f[i]=a;
      s[i]=b;
      c[i]=C;
      g[a].pb(b);
      g[b].pb(a);
    }

  dfs(0,-1,0);
  int sum1,sum2;
  sum1=sum2=0;
  for (int i=0;i<n;i++)
    if ((num[f[i]]+1)%n==num[s[i]])
      sum1+=c[i];
    else
      sum2+=c[i];
  cout<<min(sum1,sum2)<<endl;
  return 0;
}