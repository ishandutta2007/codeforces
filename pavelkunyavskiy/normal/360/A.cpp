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

#define TASKNAME "A"

#ifdef LOCAL
static struct __timestamper {
    ~__timestamper(){
        TIMESTAMP(end);
    }
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;


const int MAXN = 5000;

int a[MAXN];
int b[MAXN];
int add[MAXN];

int t[MAXN], l[MAXN], r[MAXN], d[MAXN];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

  
    int n,m;
    scanf("%d %d",&n,&m);

    for (int i = 0; i < n; i++)
        a[i] = 1e9, add[i] = 0; 

    for (int i = 0; i < m; i++){
        scanf("%d%d%d%d",&t[i],&l[i],&r[i],&d[i]);
        --l[i], --r[i];
        if (t[i] == 1){
            for (int j = l[i]; j <= r[i]; j++)
                add[j] += d[i];
        } else {
            for (int j = l[i]; j <= r[i]; j++)
                a[j] = min(a[j], d[i] - add[j]);
        }
    }

    memcpy(b, a, sizeof(b));

//    for (int i = 0; i < n; i++)
//      eprintf("%d%c", b[i], " \n"[i==n-1]);


    for (int i = 0; i < m; i++){
        if (t[i] == 1){
            for (int j = l[i]; j <= r[i]; j++)
                a[j] += d[i];
        } else {
            if (*max_element(a + l[i], a + r[i] + 1) != d[i]){
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
    for (int i = 0; i < n; i++)
        printf("%d%c", b[i], " \n"[i==n-1]);

      
    return 0;
}