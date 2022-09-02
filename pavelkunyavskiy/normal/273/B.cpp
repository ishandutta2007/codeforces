#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "B"

typedef long long ll;
typedef long double ld;

const int MAXN = 110000;

pair<int,int> a[MAXN*2];
int mod;
int n;


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    scanf("%d",&n);
    for (int i = 0; i < 2*n; i++){
        scanf("%d",&a[i].first);
        a[i].second = i % n;
    }

    scanf("%d",&mod);

    n = 2*n;
    sort(a,a+n);

    int ans = 1;

    for (int i = 0; i < n; ){
        int j = i;
        int dvd = 0;

        for (;j < n && a[i].first == a[j].first; j++)
            if (j > i && a[j] == a[j-1])
                dvd++;
        
        for (int k = 1; k <= j - i; k++)
            if (k % 2 == 1 || !dvd)
                ans = (ans * 1LL * k) % mod;
            else {
                ans = (ans * 1LL * (k/2)) % mod;
                dvd--;
            }                   

        i = j;
    }

    cout << ans % mod<< endl;

      
    return 0;
}