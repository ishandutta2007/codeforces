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

int a[1100];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    memset(a,0,sizeof(a));
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int tmp=0;
        scanf("%d",&tmp);
        a[tmp]++;
    }
    int cnt=0,maxx=0;
    for (int i=0;i<1100;i++)
        if (a[i]>0){
            cnt++;
            maxx=max(maxx,a[i]);
        }
    cout<<maxx<<" "<<cnt<<endl; 
    return 0;
}