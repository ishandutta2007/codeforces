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

#define TASKNAME "C"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

const int MAXN = 1000010;
char buf1[MAXN], buf2[MAXN];

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int n;
    scanf("%d%s%s", &n,buf1, buf2);
    --n;

    for (int i = 0; i < n; i++) {
        if (buf1[i] == 'N') buf1[i] = 'S';
        else if (buf1[i] == 'S') buf1[i] = 'N';
        else if (buf1[i] == 'W') buf1[i] = 'E';
        else if (buf1[i] == 'E') buf1[i] = 'W';
    }
    reverse(buf1, buf1 + n);
    string s = buf1;
    s += '$';
    s += buf2;

    fprintf(stderr, "%s\n", s.c_str());

    vector<int> p(s.size());
    for (int i = 1; i < (int)s.size(); i++) {
        int j = p[i-1];
        while (j && s[j] != s[i])
            j = p[j-1];
        if (s[j] == s[i]) j++;
        p[i] = j;
    }

    if (p[s.size() - 1])
        puts("NO\n");
    else
        puts("YES\n");




    return 0;
}