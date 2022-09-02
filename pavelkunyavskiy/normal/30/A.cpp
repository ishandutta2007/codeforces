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

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int64 a,b,n;
  cin>>a>>b>>n;
  for (int i=-1100;i<=1100;i++){
    int64 tmp=i;
    for (int j=0;j<n-1;j++){
        if (abs(tmp*a)>abs(b))
            break;
        tmp*=i;
    }
    if (tmp*a==b)
        {
            cout<<i<<endl;
            return 0;
        }
        
  } 
    cout<<"No solution"<<endl;
  return 0;
}