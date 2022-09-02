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


vector<pair<int,ld> > ans[100];


void solve(int n,int m,ld w){

    int pt = 0,cnt = 0;
    ld have = w;
    
    for (int i=0;i<m;i++){
        ld need = n*w/m;
        for (;need>1e-9;){
            if (fabsl(have) < 1e-9)
                pt=0,cnt++,have=w;
            if (need - have > -(1e-9)){
                ++pt;
                if (pt == 3){
                    printf("NO\n");
                    exit(0);
                }
                ans[i].pb(mp(cnt,have));
                need -= have;
                have = 0;
            }
            else {
                ans[i].pb(mp(cnt,need));
                have -= need;
                need = 0;
                ++pt;
                if (pt == 3){
                    printf("NO\n");
                    exit(0);
                }
            }
        }
    }
        
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m,w;
    cin>>n>>w>>m;
    solve(n,m,w);
    printf("YES\n");
    for (int i=0;i<m;i++)
        for (int j=0;j<ans[i].size();j++){
            cout.precision(15);
            cout << fixed << ans[i][j].first +1<<" "<<ans[i][j].second <<" \n"[j+1 == ans[i].size()];
        }
    return 0;
}