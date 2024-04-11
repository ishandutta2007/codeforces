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

#define TASKNAME "B"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#endif

typedef long long ll;
typedef long double ld;

const int MAXN = 210000;

int a[MAXN];
int b[MAXN];

int needcnt[2*MAXN];
int cnt[2*MAXN];
int cntok;
int cntneedok;

vector<int> res;
int n,m,p;


void solve(vector<int> v, int shift){
    if ((int)v.size() < m) return;
    for (int i = 0; i < m; i++){
        if (cnt[v[i]] == needcnt[v[i]]) cntok--;
        cnt[v[i]]++;
        if (cnt[v[i]] == needcnt[v[i]]) cntok++;
    }
    if (cntneedok == cntok) res.pb(shift);
    for (int i = m; i < (int)v.size(); i++){
        if (cnt[v[i]] == needcnt[v[i]]) cntok--;
        cnt[v[i]]++;
        if (cnt[v[i]] == needcnt[v[i]]) cntok++;

        if (cnt[v[i - m]] == needcnt[v[i - m]]) cntok--;
        cnt[v[i - m]]--;
        if (cnt[v[i - m]] == needcnt[v[i - m]]) cntok++;
       
        if (cntok == cntneedok)
            res.pb((i - m + 1) * p + shift);
    }
    for (int i = 0; i < (int)v.size(); i++)
        cnt[v[i]] = 0;
    cntok = 0;
}



int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    scanf("%d %d %d",&n,&m,&p);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d",&b[i]);
    vector<int> total(a, a+n);
    total.insert(total.end(), b, b+n);
    sort(total.begin(), total.end());
    total.erase(unique(total.begin(), total.end()), total.end());

    for (int i = 0; i < n; i++)
        a[i] = lower_bound(total.begin(), total.end(), a[i]) - total.begin();
    for (int i = 0; i < m; i++)
        b[i] = lower_bound(total.begin(), total.end(), b[i]) - total.begin();


    for (int i = 0; i < m; i++){
       needcnt[b[i]]++;
       if (needcnt[b[i]] == 1)
          cntneedok++;
    }

    for (int i = 0; i < p; i++){
        vector<int> v;
        for (int j = i; j < n; j += p){
            v.pb(a[j]);
//          eprintf("%d ", a[j]);
        }
//      eprintf("\n");
        solve(v, i);
    }

    sort(res.begin(), res.end());

    printf("%d\n", res.size());
    for (int i = 0; i < (int)res.size(); i++)
        printf("%d%c", res[i] + 1, " \n"[i==(int)res.size()-1]);


      
    return 0;
}