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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "A"

typedef long long ll;
typedef long double ld;


const int MAXN = 1100;

char s[2000010];
char t[2000010];

int cnt[2][2];

int res[2];

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    gets(s);
    int n;
    sscanf(s,"%d",&n);
    gets(s);
    gets(t);

    for (int i = 0; i < 2*n; i++)
        cnt[s[i]-'0'][t[i]-'0']++;


    for (int i = 0; i < n; i++){
        for (int it = 0; it < 2; it++){
            if (cnt[1][1]) res[it]++,cnt[1][1]--;
            else if (cnt[1][0]) res[it]++,cnt[1][0]--;
            else if (cnt[0][1]) cnt[0][1]--;
            else if (cnt[0][0]) cnt[0][0]--;    
            else assert(false);             
            swap(cnt[0][1],cnt[1][0]);
        }
    }
    
    if (res[0] > res[1])
        printf("First\n");
    else if (res[1] > res[0])
        printf("Second\n");
    else
        printf("Draw\n");   
      
    TIMESTAMP(end);
    return 0;
}