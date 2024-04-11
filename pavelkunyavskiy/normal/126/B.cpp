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

char s[1000*1000+100];
int  p[1000*1000+100];
bool used[1000*1000+100];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    gets(s);
    p[0] = 0;
    int n = 1;
    for (int i = 1; s[i]; i++,n++){
        int j = p[i-1];
        while (j && s[j] != s[i])
            j = p[j-1];
        if (s[j] == s[i])
            j++;
        p[i] = j;
        if (i)
            used[p[i-1]] = true;
        //cerr << i <<" "<<p[i]<<endl;
    }

    //cerr << n << endl;

    for (int i = p[n-1]; i; i = p[i-1])
        if (used[i]){
            s[i] = 0;
            puts(s);
            return 0;
        }
    puts("Just a legend");
  return 0;
}