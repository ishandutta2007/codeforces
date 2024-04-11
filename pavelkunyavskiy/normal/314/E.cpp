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

#define TASKNAME "E"

typedef long long ll;
typedef long double ld;

const int MAXN = 110000;

unsigned a[MAXN];

char s[MAXN];

unsigned pow(unsigned a,int b){
    if (!b) return 1;
    if (b % 2 == 1) return pow(a,b-1) * a;
    unsigned temp = pow(a,b/2);
    return temp * temp;
}

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    
    int n;
    gets(s);
    sscanf(s,"%d",&n);
    if (n % 2 == 1){
        printf("0\n");
        return 0;
    }
    gets(s);

    a[0] = 1;

    for (int i = 0; i < n; i++){
//      if (i % 10000 == 0){
//          TIMESTAMPf("%d",i);
//      }
        if (s[i] == '?') {
            unsigned temp = 0,temp2;
            ++i;
            int maxv = min(i+1,n-i+1);
            for (int j = 0; j <= maxv; j++){
                temp2 = a[j];
                a[j] = temp + a[j+1];
                temp = temp2;
            }
            --i;
        } else {
            int maxv = min(i+1,n-i+1);
            for (int j = maxv; j > 0; j--)
                a[j] = a[j-1];
            a[0] = 0;
        }
    }

    eprintf("%u\n",a[0]);

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (s[i] != '?')
            cnt++;
    cnt = (n - 2*cnt);

    if (cnt < 0) {
        printf("0\n");
        return 0;
    }

    cnt /= 2;
                         

    unsigned ans = a[0] * pow(25u, cnt);
    
    printf("%u\n",ans);
      
    TIMESTAMP(end);
    return 0;
}