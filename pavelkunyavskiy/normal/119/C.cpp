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

ll dp[55][55][110];
int p1[55][55][110];
int p2[55][55][110];

struct item{
    ll a,b,c;
    int num;
    bool operator<(const item& r) const{
        return c < r.c;
    }
};

item a[110];

void gen(int i,int j,int k){
    if (i == 0)
        return;
    gen(i-1,p1[i][j][k],p2[i][j][k]);
    cout << a[j].num <<" "<<a[j].a + k << endl;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m,k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++){
        cin >>a[i].a >>a[i].b >>a[i].c;
        a[i].num = i+1;
    }
    sort(a,a+m);

    memset(dp,0,sizeof(dp));
    memset(p1,-1,sizeof(p1)); 

    for (int i = 0; i <= n; i++)    
        for (int j = 0; j < m; j++)
            for (int k = 0; k <= a[j].b - a[j].a; k++){
                if (i == 0)
                    dp[i][j][k] = 0;
                else if (i == 1)
                    dp[i][j][k] = a[j].a + k;                   
                else
                    dp[i][j][k] = -(1LL<<60LL);
            }


    for (int cnt = 0; cnt < n; cnt++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j <= a[i].b - a[i].a; j++){

        
                for (int it = 0; it < 2; it++){

                    ll sum = a[i].a + j + k;
                    if (it == 1)
                        sum = (sum - k)*k;
                    
                    for (int l = i+1; l < m; l++)
                        if (a[l].c > a[i].c && (a[l].a <= sum && sum <= a[l].b)){
                            if (dp[cnt+1][l][sum - a[l].a] < dp[cnt][i][j] + sum){
                                dp[cnt+1][l][sum - a[l].a] = dp[cnt][i][j] + sum;
                                p1[cnt+1][l][sum - a[l].a] = i;
                                p2[cnt+1][l][sum - a[l].a] = j;
                            }
                        }                   
                }
                                    
            }

  ll ans = 0;

  for (int i = 0; i < m; i++)
    for (int j =0; j <= a[i].b - a[i].a; j++)
        ans = max(ans,dp[n][i][j]);



  for (int i = 0; i < m; i++)
    for (int j =0; j <= a[i].b - a[i].a; j++)
        if (ans && dp[n][i][j] == ans){
            printf("YES\n");
            gen(n,i,j);
            return 0;
        }

  printf("NO\n");
  return 0;
}