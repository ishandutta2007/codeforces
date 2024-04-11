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

int a[500];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int last=0;
    int n,k;
    scanf("%d %d",&n,&k);
    int c;
    scanf("%d",&c);
    for (int i=0;i<c;i++)
        scanf("%d",&a[i]);
    a[c]=n+1;
    int cnt=0;
    int ptr=0;
    for (int i=1;i<=n;i++){
        if (a[ptr]==i){
            cnt++;
            ++ptr;
            last=i;
            continue;
        }
        if (i==last+k){
            last=i;
            ++cnt;          
            continue;
        }           
    }
    cout<<cnt<<endl;
    return 0;
}