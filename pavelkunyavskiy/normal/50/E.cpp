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



inline int get(int mv,int chet){
    return (mv+chet)/2;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m;
    cin>>n>>m;
    int64 ans=0;
    for (int i=1;i<=n;i++){
        ans+=min(m*1LL,i*1LL*i)*2;
        if (i*1LL*i<=m) ans--;
    }
    int mv;
    for (int i=1;i<=2*n;i++){
        mv=2*n-i;
        mv=min(mv,m/i);
        ans-=max(0,get(mv,i&1)-1);
    }
    cout<<ans<<endl;
    return 0;
}