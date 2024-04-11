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

int f[MAXN];
int n,m;

void upd(int a,int dlt){
    for (;a < n; a = (a|(a+1))){
        f[a] += dlt;
    }
}

int get(int r){
    int res = 0;
    for (;r != -1; r = (r&(r+1))-1)
        res += f[r];

    return res;
}

vector<pair<int,int> > req[MAXN];
vector<int> pos[MAXN];
int a[MAXN];


int ans[MAXN];


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d %d",&n,&m);

    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);

    for (int i = 0; i < m; i++){
        int l,r;
        scanf("%d %d",&l,&r);
        --l,--r;
        req[r].pb(mp(l,i));
    }

    for (int i = 1; i <= n; i++)
        pos[i].pb(-1);

    for (int i = 0; i < n; i++){
        if (a[i] <= n){
            if ((int)pos[a[i]].size() > a[i]){              
                upd(pos[a[i]][pos[a[i]].size() - a[i] - 1] + 1, -1);
                upd(pos[a[i]][pos[a[i]].size() - a[i]] + 1, 1);
            } 
            pos[a[i]].pb(i);
            if ((int)pos[a[i]].size() > a[i]){
                upd(pos[a[i]][pos[a[i]].size() - a[i] - 1] + 1, 1);
                upd(pos[a[i]][pos[a[i]].size() - a[i]] + 1, -1);
            } 
        }
        for (int j = 0; j < (int)req[i].size(); j++){
            ans[req[i][j].second] = get(req[i][j].first);
        }
    }

    for (int i = 0; i < m; i++)
        printf("%d\n",ans[i]);
      
    return 0;
}