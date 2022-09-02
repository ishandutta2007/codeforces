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
    int n,x1,y1,x2,y2;
    cin>>n>>x1>>y1>>x2>>y2;
    if (x1 > x2){
        swap(x1,x2);
        swap(y1,y2);
    }
    if (x1==0 && x2==n){
        cout<<n+min(y1+y2,n-y1+n-y2)<<endl;         
        return 0;
    }
    if (y1 > y2){
        swap(x1,x2);
        swap(y1,y2);
    }
    if (y1==0 && y2==n){
        cout<<min(x1+x2,n-x1+n-x2)+n<<endl;
        return 0;
    }
    cout<<abs(x1-x2)+abs(y1-y2)<<endl;
    return 0;
}