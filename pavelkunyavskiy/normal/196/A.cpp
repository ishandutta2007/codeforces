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


char s[110000];
char t[110000];

char mv;

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    gets(s);
    mv = 'a';

    int l = strlen(s);
    int ptr = 0;
    for (int i = l-1; i >= 0; i--){
        mv = max(mv, s[i]);
        if (s[i] >= mv)
            t[ptr++] = s[i];
    }

    reverse(t,t+ptr);
    t[ptr++] = 0;
    puts(t);

  return 0;
}