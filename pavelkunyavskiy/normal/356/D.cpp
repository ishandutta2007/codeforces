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


const int MAXN = 71000;

unsigned int can[MAXN / 32];
unsigned int already[MAXN / 32];
int prev[MAXN];
pair<int,int> a[MAXN];



int ans[MAXN];
vector<int> in[MAXN];

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n,s;
    scanf("%d %d",&n,&s);

    for (int i = 0; i < n; i++){
        scanf("%d",&a[i].first);
        a[i].second = i;
    }

    sort(a, a+n);

    if (s < a[n-1].first){
        printf("-1\n");
        return 0;
    }

    can[0] = 1;
    already[0] = 1;

    memset(prev, -1, sizeof(prev));

    for (int it = 0; it < n - 1; it++){
        int shift = a[it].first;
        int shiftd = shift >> 5;
        int shiftm = shift & 31;

        if (shiftm == 0){
            for (int i = MAXN / 32; i >= 0; i--)
                if (i + shiftd < MAXN / 32)
                    can[i + shiftd] |= can[i];
        } else {
            for (int i = MAXN / 32; i >= 0; i--){
                if (i + shiftd + 1 < MAXN / 32)
                    can[i + shiftd + 1] |= can[i] >> (32 - shiftm);
                if (i + shiftd < MAXN / 32)
                    can[i + shiftd] |= can[i] << shiftm;
            }
        }

        for (int i = 0; i < MAXN / 32; i++){
            unsigned int newv = can[i] & ~already[i];
            already[i] |= can[i];
            while (newv) {
                int x = __builtin_ctz(newv);
                newv = newv & (newv - 1);
                prev[i * 32 + x] = it;
            }
        }
    }

    if (prev[s - a[n-1].first] == -1 && s != a[n-1].first){
        printf("-1\n");
        return 0;
    }

    vector<int> ids;
    for (int i = s - a[n-1].first; i > 0; i -= a[prev[i]].first)
        ids.pb(prev[i]);

    
    for (int i = 0; i < (int)ids.size(); i++) {
        ans[a[ids[i]].second] = a[ids[i]].first;
        a[ids[i]].second = -1;
    }

    int last = -1;
    for (int i = 0; i < n; i++){
        if (a[i].second == -1) continue;
        if (last != -1) {
            in[a[i].second].pb(a[last].second);
            ans[a[i].second] = a[i].first - a[last].first;
        } else {
            ans[a[i].second] = a[i].first;
        }
        last = i;
    }

    for (int i = 0; i < n; i++){
        printf("%d", ans[i]);
        printf(" %d", in[i].size());
        for (int j = 0; j < (int)in[i].size(); j++)
            printf(" %d", in[i][j]+1);
        printf("\n");
    }                

          
    return 0;
}