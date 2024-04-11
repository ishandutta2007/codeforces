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

#define dec botva

using namespace std;

typedef long long int64;
typedef long double ld;

struct obj{
    int c,w,dec;
};

obj compto;

bool comp(const obj& a){
    return a.c * 1LL * compto.w < a.w *1LL * compto.c;
}

bool eql(const obj& a){
    return a.c * 1LL * compto.w == a.w *1LL * compto.c;
}

void get(obj* l,obj* r,int W){
    if (r-l <= 1)
        return;
    if (W == 0)
        return;
    compto =*(l + rand()%(r-l));
    partition(l,r,comp);
    obj* mid = l;
    int64 sum = 0;
    for (;comp(*mid);++mid)
        sum += mid->w;
    if (sum > W)
        get(l,mid,W);
    for (;mid!= r && eql(*mid);++mid)
        sum += mid -> w;
    if (sum > W)
        return;
    get(mid,r,W-sum);
}

obj have[510000];
int dec[510000];

int64 ians;
ld dans;

void add(int cnt,int all,int cost){
//  cerr << cnt << " " << all << " "<< cost << endl;
    int64 tmp = cnt * 1LL * cost;
    ians += tmp/all;
    tmp%=all;
    dans += ((ld)tmp)/all;  
    while (dans >= 1-(1e-9)){
        ians++;
        dans-=1;
    }
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m,W;
    scanf("%d %d %d",&n,&m,&W);
    for (int i=0;i<m;i++)
        scanf("%d",&have[i].w);
        
    for (int i=0;i<m;i++)
        scanf("%d",&have[i].c);
        
    for (int i=0;i<m;i++)
        scanf("%d",&have[i].dec);
        
    for (int it=0;it<n;it++){
        get(have,have+m,W);
        int tmp = W;
        for (int i=0;i<m;i++)
            if (tmp >= have[i].w){
                tmp -= have[i].w;
                ians += have[i].c;
            }
            else {
                add(tmp,have[i].w,have[i].c);
                tmp = 0;
            }
        for (int i=0;i<m;i++)
            have[i].c -= have[i].dec;
            
        
//      cout.precision(15);
//      cout<<ians<<"."<<max(0,int(dans*(1e9)))<<endl<<endl;;   
            
    }

    printf("%I64d.%015I64d",ians,max(0LL,int64(dans*(1e15))));
    return 0;
}