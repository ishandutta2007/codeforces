#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

string s;

int cnt1[10];
int cnt2[10];
char ans [110000];
char ans2[110000];

int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    getline(cin,s);
    int n = s.size();
    int n0 = n;
    for (int i = 0; i <n ; i++)
        cnt1[s[i]-'0']++,cnt2[s[i]-'0']++;
    ans[n] = ans2[n] = 0;

    int best = 0;
    int bestid = -1;
    int bestnul = cnt1[0];

    for (int k = 0; k <= cnt1[0]; k++){
       cnt1[0] -= k;
       cnt2[0] -= k;

       for (int i = 1; i < 10; i++){
           if (!cnt1[i] || !cnt2[10-i])
               continue;
           int cur = k+1;
           for (int j = 0; j < 10; j++)   
               cur += min(cnt1[j] - (i==j), cnt2[9-j] - ((10-i) == (9-j)));
      
           if (best < cur){   
               best = cur,bestid = i,bestnul = k;
           }
       }

       cnt1[0] += k;
       cnt2[0] += k;
    }

    for (int i = 0; i < bestnul; i++){
        --n,ans[n] = 0,ans2[n] = 0;
        --cnt1[0],--cnt2[0];
    }

    if (bestid != -1){
        --n,ans[n] = bestid,ans2[n] = 10-bestid;
        --cnt1[bestid], --cnt2[10-bestid];

        for (int i = 0; i < 10; i++)
            for (;cnt1[i] && cnt2[9-i];){
                --n,ans[n] = i,ans2[n] = 9-i;
                cnt1[i]--;
                cnt2[9-i]--;
            }

    }

    int ptr = 0;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < cnt1[i]; j++)
            ans[ptr++] = i;
    ptr = 0;;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < cnt2[i]; j++)
            ans2[ptr++] = i;

    for (int i = 0; i < n0; i++)
        ans[i] += '0',ans2[i] += '0';
    puts(ans);
    puts(ans2);
    return 0;
}