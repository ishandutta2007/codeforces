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

int main(){
  int t;
  cin>>t;
  for (int i=0;i<t;i++){
      int a,b;
      cin>>a>>b;
      if (b==0){
          printf("1\n");
          continue;
      }
      if (a==0){
          printf("0.5\n");
      continue;
      }      
      ld c = min(b*1.0,a/4.0);
      ld res = 0.5 + c/(2.0*b) - c*c/(a*1LL*b);
      cout.precision(15);
      cout<<fixed<<res<<endl;
   }
   return 0;
}