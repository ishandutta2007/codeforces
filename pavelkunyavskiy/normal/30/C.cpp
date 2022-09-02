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

struct cel{
    int x,y,t;
    ld p;
};

bool operator<(const cel& a,const cel& b){
    return a.t<b.t;
}

cel a[10000];
ld t[10000];

bool can(const cel& a,const cel& b){
    int dx=a.x-b.x;
    int dy=a.y-b.y;
    int dt=abs(a.t-b.t);
    if (dx*1LL*dx+dy*1LL*dy<=dt*1LL*dt)
        return true;
    return false;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        cin>>a[i].x>>a[i].y>>a[i].t>>a[i].p;
    sort(a,a+n);
    for (int i=0;i<n;i++){
        t[i]=0;
        for (int j=0;j<i;j++)
            if (can(a[i],a[j]))
                t[i]=max(t[i],t[j]);
        t[i]+=a[i].p;
    }
    ld ans=0;
    for (int i=0;i<n;i++)
        ans=max(ans,t[i]);
    cout.precision(15);
    cout<<fixed<<ans<<endl;
    return 0;
}