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

typedef long long int64;
typedef long double ld;

char s[11000];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    gets(s);
    int n;
    sscanf(s,"%d",&n);
    memset(s,0,sizeof(s));
    gets(s);
    int ans = 0;
    int size = 0;
    for (int i=0;s[i];){
        int j = i;
        while (s[j] != '.' && s[j] != '?' && s[j] != '!')
            j++;
        j++;
        if (size +(j-i) > n){
            ans ++;
            size = 0;
            if (s[i] == ' ')
                i++;
        }
        size += (j-i);
        if (size > n){
            printf("Impossible\n");
            return 0;
        }       
        i=j;
    }
    if (size > 0)
        ans ++;
    
    cout << ans << endl;
    
    return 0;
}