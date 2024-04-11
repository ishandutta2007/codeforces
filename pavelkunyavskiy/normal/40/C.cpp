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

int n,m;
int x,y;

int64 ans;




int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>n>>x>>m>>y;
    if (x==y){
        cout<<max(n,m)+1<<endl;
        return 0;
    }   
    if (x>y){
        swap(x,y);
        swap(n,m);          
    }   
    for (int i=1;i<=n;i++){
        int l,r;
        l=abs(y-x-i);
        ++l;
        r=abs(y-x+i);
        --r;
        r=min(r,m);
        if (l>r) continue;
        ans+=(r-l)*2+1;             
        if (y<x+i) ans++;
//          cerr<<l<<" "<<r<<" "<<ans<<endl;
    }
    cout<<ans+n+m+1<<endl;
    return 0;
}