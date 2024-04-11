#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <iterator>
#include <algorithm>
#include <queue>
#include <bitset>
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

#define y1 botvay1

using namespace std;

typedef long long int64;
typedef long double ld;

bitset<1001> in[1100];

int x1[1100],y1[1100];
int x2[1100],y2[1100],r2[1100];
      
    
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ld start=clock();
  #endif
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for (int i=0;i<n;i++)
        scanf("%d %d",&x1[i],&y1[i]);
    for (int i=0;i<m;i++)
        scanf("%d %d %d",&r2[i],&x2[i],&y2[i]);

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            int dx=x2[j]-x1[i];
            int dy=y2[j]-y1[i];
//            cerr<<dx*dx+dy*dy<<" "<<r2[j]*r2[j]<<endl;
            if (dx*1LL*dx+dy*1LL*dy<=r2[j]*1LL*r2[j]){
                in[i].set(j);
    //            cerr<<"!!!"<<endl;
            }
        }

  //  cerr<<in[0].test(0)<<" "<<in[1].test(0)<<endl;
//    cerr<<in[0].count()<<" "<<in[1].count()<<endl;

    for (int i=0;i<k;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        --a;--b;
        printf("%d\n",(int)(in[a]^in[b]).count());
    }

  #ifndef ONLINE_JUDGE
    cerr<<(clock()-start)/CLOCKS_PER_SEC<<endl;
  #endif
    return 0;
}