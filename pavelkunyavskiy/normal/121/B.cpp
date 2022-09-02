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

int n,k;
string s;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  cin >> n >> k >> s;

  for (int i = 0; i < n-1 && k; i++){
      if (s[i] == '4' && s[i+1] == '7'){
        --k;
        if (i % 2 == 0)
            s[i+1] = '4';
        else {          
            s[i] = '7';
            if (!i || s[i-1] != '4')
                continue;
            k %= 2;
            if (k == 1){
                --k;
                s[i] = '4';
            }
                
        }       
      }
//      cerr << k <<" "<<s<<endl;
  }

  cout << s << endl;

  return 0;
}