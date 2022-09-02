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
#include <bitset>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

//#define MAXTEST

using namespace std;

typedef long long int64;
typedef long double ld;

bitset<710> g[1000];
bitset<710> temp;
int64 cnt2[710][710];
int cnt[710];
int n,m;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    
    #ifndef MAXTEST
        scanf("%d %d",&n,&m);
        for (int i=0;i<m;++i){
            int a,b;
            scanf("%d %d",&a,&b);
            --a,--b;
            g[a].set(b);
            g[b].set(a);
            cnt[a]++;
            cnt[b]++;
        }
    #else
        n=700;
        m=700*(700-1)/2;
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++){
                int a,b;
                a=i;b=j;
                g[a].set(b);
                g[b].set(a);
                cnt[a]++;
                cnt[b]++;
            }
    #endif
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            cnt2[i][j]=cnt2[j][i]=(g[i]&g[j]).count();
    int64 ans=0;
    bool q,q1;
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++){
            if (g[i].test(j)==0) continue;
            temp=g[i]&g[j];
            for (int k=0;k<n;k++){
                if (k==i || k==j) continue;
                q=(g[i].test(j) && g[k].test(j));
                q1=(g[j].test(i) && g[k].test(i));
                ans+=(cnt2[i][k]-q)*(cnt2[j][k]-q1);
                //ans-=(temp&g[k]).count();
            }
        }
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++){
            if (!g[i].test(j)) continue;
            for (int k=j+1;k<n;k++){
                if (!g[i].test(k)) continue;
                if (!g[j].test(k)) continue;
                ans-=cnt[i]-2;
                ans-=cnt[j]-2;
                ans-=cnt[k]-2;
            }       
        }
    ans/=5;

//  cout<<ans/5<<endl;
    cout<<ans<<endl;
    
    return 0;
}