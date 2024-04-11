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

#define TASKNAME "B"

typedef long long ll;
typedef long double ld;

char s[210000];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

  gets(s);
  int tmp = strlen(s);
  s[tmp++] = ' ';
  s[tmp++] = 0;
  string token = "";
  bool inquote = false;

  for (int i = 0; s[i]; i++){
    if (s[i] == '"') {
        if (inquote)
            printf("<%s>\n",token.data());
        inquote ^= 1;
        token = "";
    }
    else if (s[i] == ' '){
        if (inquote)
            token += " ";
        else {
            if (token.size())
                printf("<%s>\n",token.data());
            token = "";
        }
    }
    else
        token += s[i];        
  }
      
  TIMESTAMP(end);
  return 0;
}