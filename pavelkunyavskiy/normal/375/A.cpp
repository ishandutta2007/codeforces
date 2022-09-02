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

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "A"

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



int cnt[10];
int end[10];

char s[1000100];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    {
    string s = "1689";
    do {
        int x;
        sscanf(s.data(),"%d",&x);
        end[x % 7] = x;
    } while (next_permutation(s.begin(),s.end()));
    }
    gets(s);
    for (int i = 0; s[i]; i++)
        cnt[s[i] - '0']++;

    cnt[1]--;
    cnt[6]--;
    cnt[8]--;
    cnt[9]--;

    int ptr = 0;
    int cur = 0;
    for (int i = 1; i < 10; i++){
        for (int j = 0; j < cnt[i]; j++){
            s[ptr++] = '0' + i;
            cur = (cur * 10 + i) % 7;
        }
    }
    cur = (cur * 10000) % 7;
    eprintf("%d\n", cur);
    s[ptr++] = 0;
    printf("%s",s);
    printf("%d",end[(7 - cur) % 7]);
    ptr = 0;
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < cnt[i]; j++){
            s[ptr++] = '0' + i;
            cur = (cur * 10 + i) % 7;
        }
    }
    s[ptr++] = 0;
    printf("%s",s);
    printf("\n");
      
    return 0;
}