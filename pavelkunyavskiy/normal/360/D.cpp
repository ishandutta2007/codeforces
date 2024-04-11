//#include <iostream>
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
#include <sstream>
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

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "D"

#ifdef LOCAL
static struct __timestamper {
    ~__timestamper(){
        TIMESTAMP(end);
    }
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;

int pow(int a,int b,int p){
    int res = 1;
    for (;b; b>>=1, a = (a * 1LL *a) % p)
       if (b&1) res = (res * 1LL * a) % p;  
    return res;
}

vector<int> divs;
vector<bool> have;

int getOrd(int a,int p){
    for (int i = 0; i < (int)divs.size(); i++)
        if (pow(a, divs[i], p) == 1)
            return divs[i];
    assert(false);
}

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n,m,p;

    scanf("%d %d %d",&n,&m,&p);

    for (int i = 1; i*i <= p-1; i++){
        if ((p-1) % i == 0){
            divs.pb(i);
            if (i != (p - 1) / i)
                divs.pb((p - 1) / i);
        }
    }

    sort(divs.begin(), divs.end());
    have.resize(divs.size());

    for (int i = 0; i < n; i++){
        int a;
        scanf("%d",&a);
        a = getOrd(a, p);
        have[find(divs.begin(), divs.end(),a) - divs.begin()] = 1;
    }

    vector<int> ords;

    for (int i = 0; i < (int)divs.size(); i++)
        if (have[i]) {
            ords.pb((p - 1) / divs[i]);
//              eprintf("%d\n", ords.back());
        }

    int g = p - 1;
    for (int i = 0; i < m; i++){
        int b;
        scanf("%d",&b);
        g = __gcd(g, b);
    }

    for (int i = 0; i < (int)ords.size(); i++)
        ords[i] = ords[i] * __gcd(g, (p-1) / ords[i]);


    sort(ords.begin(), ords.end());
    ords.erase(unique(ords.begin(), ords.end()), ords.end());

    have = vector<bool>(n, 0);

    vector<int> cnt(divs.size());

    int ans = 0;

    for (int i = (int)divs.size() - 1; i >= 0; i--){
        cnt[i] = (p - 1) / divs[i];
        for (int j = i+1; j < (int)divs.size(); j++)
            if (divs[j] % divs[i] == 0)
                cnt[i] -= cnt[j];
        for (int j = 0; j < (int)ords.size(); j++)
            if (divs[i] % ords[j] == 0){
                ans += cnt[i];
                break;
            }                       
    }

    printf("%d\n", ans);
            
      
    return 0;
}