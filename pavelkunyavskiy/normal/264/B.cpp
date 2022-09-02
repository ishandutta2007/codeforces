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

int ans[MAXN];

int p[MAXN];

vector<int> primes;


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    for (int i = 2; i < MAXN; i++){
        if (p[i] == 0){
            p[i] = i;
            primes.pb(i);
        }
        for (int j = 0; j < (int)primes.size() && primes[j] <= p[i] && i * primes[j] < MAXN; j++)
            p[primes[j] * i] = primes[j];
    }

    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        int x;
        scanf("%d",&x);
        int tmp = x;
        //cerr << x <<" : ";
        int best = 0;
        while (x != 1){
            best = max(best,ans[p[x]]);
            x /= p[x];
        }
        //cerr <<"!"<<best <<"!"<<endl;
        best++;
        x = tmp;
        ans[1] = max(ans[1],best);
        while (x != 1){
            ans[p[x]] = max(best,ans[p[x]]);
            x /= p[x];
        }                 
        //cerr <<ans[1] <<" "<<ans[2] <<" "<<ans[3] << endl;
    }

    cout << ans[1] << endl;
      
    return 0;
}