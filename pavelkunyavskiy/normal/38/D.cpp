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
#define forn(i,n) for(int i=0;i<(n);++i)
#define ford(i,n) for(int i=(n)-1;i>=0;--i)
#define y1 botva

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;

int x1[110];
int y1[110];
int x2[110];
int y2[110];

ld xc[110];
ld yc[110];
int m[110];

const ld eps=1e-05;

bool inside(ld x1,ld y1,ld x2,ld y2,ld a,ld b){
//  cerr<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<a<<" "<<b<<endl;
    if (a<x1-eps || a>x2+eps)
        return false;
    if (b<y1-eps || b>y2+eps)
        return false;
    cerr<<"!!!!!!"<<endl;
    return true;
}

bool check(int k){
    ld x=0,y=0;
    int m=0;
    for (int i=k;i>=0;i--){
        x=(x*m+xc[i]*::m[i])/(m+::m[i]);
        y=(y*m+yc[i]*::m[i])/(m+::m[i]);
        m+=::m[i];
        if (i==0){
            if (!inside(x1[i],y1[i],x2[i],y2[i],x,y))
                return false;
        }
        else {
            if (!inside(max(x1[i],x1[i-1]),max(y1[i],y1[i-1]),min(x2[i],x2[i-1]),min(y2[i],y2[i-1]),x,y))
                return false;       
        }
    }
    return true;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
        int a=abs(x2[i]-x1[i]);
        m[i]=a*a*a;
        xc[i]=(x1[i]+x2[i])/2.0;
        yc[i]=(y1[i]+y2[i])/2.0;
        if (x1[i]>x2[i])
            swap(x1[i],x2[i]);
        if (y1[i]>y2[i])
            swap(y1[i],y2[i]);
        if (!check(i)){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("%d\n",n);
    return 0;
}