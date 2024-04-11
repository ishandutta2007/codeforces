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

#define y1 boyva235

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

int x[110000];
int x1,y1;
int n,k;

ld dest(int x,int y,int x1,int y1){
    ld dx=x-x1;
    ld dy=y-y1;
    return sqrtl(dx*dx+dy*dy);
}

ld dest(int p){
    return dest(x[p],0,x1,y1);
}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d",&n,&k);
    --k;
    for (int i=0;i<n;i++)
        scanf("%d",&x[i]);
    scanf("%d %d",&x1,&y1);
    if (k==n){
        sort(x,x+n);
        ld ans=dest(0)+x[n-1]-x[0];
        ans=min(ans,dest(n-1)+x[n-1]-x[0]);
        cout.precision(15);
        cout<<fixed<<ans<<endl;
        return 0;
    }
    int sx=x[k];
    sort(x,x+n);
    for (int i=0;i<n;i++)
        if (x[i]==sx){
            k=i;
            break;
        }
    ld ans=1e+100;
    for (int i=0;i<=k;i++){     
        ld tmp1=x[k]-x[i]+x[n-1]-x[i]+dest(n-1);
        tmp1=min(tmp1,x[n-1]-x[k]+x[n-1]-x[i]+dest(i));
        if (i!=0){
            tmp1+=x[i-1]-x[0];
            tmp1+=min(dest(0),dest(i-1));
        }
        ans=min(ans,tmp1);
    }
    for (int i=k;i<n;i++){
        ld tmp1=x[i]-x[k]+x[i]-x[0]+dest(0);
        tmp1=min(tmp1,x[k]-x[0]+x[i]-x[0]+dest(i));
        if (i!=n-1){
            tmp1+=x[n-1]-x[i+1];
            tmp1+=min(dest(i+1),dest(n-1));
        }
        ans=min(ans,tmp1);
    }
    cout.precision(15);
    cout<<fixed<<ans<<endl;
    return 0;
}