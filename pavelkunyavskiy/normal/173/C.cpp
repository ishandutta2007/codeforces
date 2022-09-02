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


int best = -(1<<30);

int sum[510][510];
int ans1[510][510]; 
int ans2[510][510];
int a[510][510];
int n,m;

void init(){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = a[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
}

int get(int lx,int rx,int ly,int ry){
    return sum[rx+1][ry+1] - sum[rx+1][ly] - sum[lx][ry+1] + sum[lx][ly];
}


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d",&a[i][j]);
    init();

    memcpy(ans2,a,sizeof(a));


    for (int sz = 3; sz <= n && sz <= m; sz+=2){
        for (int i = 0; i + sz <= n; i++)
            for (int j = 0; j + sz <= m; j++){
                ans1[i][j] = get(i,i+sz-1,j,j+sz-1) - a[i+1][j] - ans2[i+1][j+1];
//                cerr << ans1[i][j] <<" ";
                best = max(best,ans1[i][j]);
            }
        memcpy(ans2,ans1,sizeof(ans1));
    }


    cout << best << endl;


    return 0;
}