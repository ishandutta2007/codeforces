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

typedef long long int64;
typedef long double ld;

int next[1100];
int d[1100];
bool used[1100];
int in[1100];
int fin;

int findd(int v){
    if (v == -1)
        return 1<<30;
    if (used[v])
        return -1;
    used[v] = true;
    if (next[v] == -1){
        fin = v;
        return (1<<30);
    }                  
    int x = findd(next[v]);
    return min(x,d[v]);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m;
    scanf("%d %d",&n,&m);
    memset(next,-1,sizeof(next));
    for (int i = 0; i < m; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        next[a-1] = b-1;
        d[a-1] = c;
        in[b-1]++;
    }
    vector<pair<pair<int,int>,int> > ans;
    for (int i = 0; i < n; i++)
        if (in[i] == 0){
            int x = findd(i);
            if (x != -1 && i != fin)
                ans.pb(mp(mp(i,fin),x));        
        }
    printf("%d\n",int(ans.size()));
    for (int i = 0;i < ans.size(); i++)
        printf("%d %d %d\n",ans[i].first.first+1,ans[i].first.second+1,ans[i].second);
    return 0;
}