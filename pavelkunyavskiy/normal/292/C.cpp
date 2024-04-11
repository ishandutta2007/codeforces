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

#define TASKNAME "C"

typedef long long ll;
typedef long double ld;


int ok2[255];

char buf[100];
char buf2[100];

vector<string> ans;

void check(int a,int b,int c,int d){
    if (a > 255)
        return;
    sprintf(buf2,"%d%d%d%d",a,b,c,d);
    int len = strlen(buf2);
    for (int i = 0; i < len - i - 1; i++)
        if (buf2[i] != buf2[len-i-1])
            return;
    sprintf(buf2,"%d.%d.%d.%d",a,b,c,d);
    ans.pb(buf2);
}
                                  
int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    int need = 0;
    for (int i = 0; i < n; i++){
        int x;
        scanf("%d",&x);
        need |= 1<<x;
    }

    ok2[0] = 1;
    for (int i = 1; i <= 255; i++){
        int j = i;
        ok2[i] = 0;               
        while (j) {
            ok2[i] |= (1<<(j % 10));
            j /= 10;
        }
    }

    for (int i = 0; i <= 255; i++)
        for (int j = 0; j <= 255; j++)
            for (int k = 0; k <= 255; k++)
            if ((ok2[i]|ok2[j]|ok2[k]) == need){
                sprintf(buf,"%d%d%d",i,j,k);
                int len = strlen(buf);
                check(buf[len-1]-'0',i,j,k);
                if (buf[len-1] != '0')
                    check((buf[len-1]-'0')*10 + (buf[len-2]-'0'),i,j,k);
                if (buf[len-1] != '0')
                    check((buf[len-1]-'0')*100 + (buf[len-2]-'0')*10 + (buf[len-3]-'0'),i,j,k);
            }

    printf("%d\n",ans.size());
    sort(ans.begin(),ans.end());
    for (int i = 0; i < (int)ans.size(); i++)
        printf("%s\n",ans[i].data());
      
    TIMESTAMP(end);
    return 0;
}