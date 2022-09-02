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

pair<int,int> a[MAXN];
int n,k;



int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d %d",&n,&k);
    ll b;
    cin >> b;
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i].first);
        a[i].second = i;
    }
    --n;
    sort(a,a+n);
    reverse(a,a+n);

    ll sum = 0;
    for (int i = 0; i < k-1; i++)
        sum += a[i].first;

    int ans = n+1;

    for (int i = 0; i < n; i++)
        if (sum + a[max(k-1,i)].first > b)    
            ans = min(ans,a[i].second+1);
        

    cout << ans << endl;

  return 0;
}