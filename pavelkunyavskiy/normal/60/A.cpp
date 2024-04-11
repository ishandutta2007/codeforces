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
    int n,m;
    scanf("%d %d",&n,&m);
    int minn,maxx;
    minn=0;
    maxx=n+1;
    char s[10];
    for (int i=0;i<m;i++){
        int v;
        scanf(" To the %s of %d",s,&v);
        string t=s;
        if (t=="right")
            minn=max(minn,v);
        else
            maxx=min(maxx,v);
    }
    int ans=maxx-minn-1;
    if (ans<=0)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}