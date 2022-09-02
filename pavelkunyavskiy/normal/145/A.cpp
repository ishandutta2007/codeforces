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

string s,t;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
     getline(cin,s);
     getline(cin,t);

     int a,b;
     a=b=0;

     for (int i = 0; i < (int)s.size(); i++){
        if (s[i] =='4' && t[i] == '7')
            a++;
        else if (s[i] == '7' && t[i] == '4')
            b++;            
     }
     cout << max(a,b) << endl;
  return 0;
}