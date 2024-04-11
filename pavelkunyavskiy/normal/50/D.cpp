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

ld t[2][1000];
ld dist[1000];
int n,k;
ld prob[1000];
ld e;

ld solve(ld R){
    ld *t1,*t2;
    for (int i=0;i<n;i++)
        if (dist[i] <= R+(1e-09))
            prob[i]=1;
        else
            prob[i]=exp(1-dist[i]*dist[i]/(R*R));
    t1=t[0];
    t2=t[1];
    for (int i=0;i<n;i++){
        t1[i]=t2[i]=0;
    }
    t1[0]=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            t2[j]+=t1[j]*(1-prob[i]);
            t2[j+1]+=t1[j]*prob[i];
        }
        swap(t1,t2);
        for (int j=0;j<n;j++)
            t2[j]=0;
    }
    ld ans=0;
    for (int i=0;i<k;i++)
        ans+=t1[i];
    return ans;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>n>>k>>e;
    e/=1000;
    int x0,y0;
    cin>>x0>>y0;
    for (int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        dist[i]=sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0));      
    }
    ld l=1e-15;
    ld r=1e+5;
    for (int i=0;i<100;i++){
        ld mid=(l+r)/2;
        if (solve(mid) > e)
            l=mid;
        else
            r=mid;
    }
    cout.precision(15);
    cout<<fixed<<(l+r)/2<<endl;
    return 0;
}