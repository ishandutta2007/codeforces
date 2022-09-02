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
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
using namespace std;

int q[1010];
vector<int> p[1010];
vector<int> c[1010];

bool cmp(int a,int b){
    return q[a]>q[b];
}

int a[1010];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n;
  scanf("%d",&n);
  for (int i=0;i<n;i++)
    scanf("%d",&q[i]);
  int m;
  scanf("%d",&m);
  for (int i=0;i<m;i++){
    int a,b,w;
    scanf("%d %d %d",&a,&b,&w);
    --a,--b;
    p[b].pb(a);
    c[b].pb(w);
  }
  for (int i=0;i<n;i++)
    a[i]=i;
  sort(a,a+n,cmp);
  int ans=0;
  bool q=false;
  for (int i=0;i<n;i++)
    {
        int v=a[i];
        int sz=p[v].size();
        int tans=1<<25;
        for (int i=0;i<sz;i++)
                tans=min(tans,c[v][i]);

        if (tans==(1<<25))
            {
                if (q){
                    printf("-1\n");
                    return 0;
                }
                q=true;
                continue;
            }
        ans+=tans;
    }
  cout<<ans<<endl;
  return 0;
}