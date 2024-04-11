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
    int x,y;
    cin>>x>>y;
    int d2=x*x+y*y;
    int l=int(sqrt(d2));
    for (;(l+1)*(l+1)<=d2;l++);
    if (l*l==d2){
        printf("black\n");
        return 0;
    }   
    if ((l%2==0) ^ (x>0) ^ (y>0))
        printf("black\n");
    else
        printf("white\n");  

    return 0;
}