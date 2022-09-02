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


int a[15][110];
int b[15][110];
int c[15][110];

int n,m,k;

ll solve(int x,int y){
    vector<pair<ll,int> > v;

    //cerr << endl;

    for (int i = 0; i < m; i++)
        if (b[y][i] - a[x][i] > 0){
            v.pb(mp(b[y][i] - a[x][i], c[x][i]));
        //    cerr << b[y][i] - a[x][i] <<" "<<c[x][i] << endl;
        }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    ll ans = 0;
    int  cnt = 0;

    for (int i = 0; i < (int)v.size(); i++){
        ans += min(v[i].second,k - cnt) * 1LL * v[i].first;
        cnt += min(v[i].second,k - cnt);
    }

    //cerr << x <<" "<<y<<" "<<ans << endl;

    return ans;
}

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d %d %d",&n,&m,&k);

    for (int i = 0; i < n; i++){
       scanf(" %*s");
       for (int j = 0; j < m; j++)
          scanf("%d %d %d",&a[i][j],&b[i][j],&c[i][j]);
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                ans = max(ans,solve(i,j));

    cout << ans << endl;
    return 0;
}