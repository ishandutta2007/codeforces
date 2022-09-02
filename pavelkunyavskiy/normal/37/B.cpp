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

int p[1100];
int dmg[1100];
bool used[1100];
vector<pair<int,int> > ans;

int td,zd;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int maxx,r,n;
    scanf("%d %d %d",&n,&maxx,&r);
    for (int i=0;i<n;i++)
        scanf("%d %d",&p[i],&dmg[i]);
    zd=maxx;
    for (int i=0;i<5000;i++){
        zd-=td;
        zd+=r;
        zd=min(zd,maxx);
//      cerr<<zd<<" "<<ans.size()<<endl;
        if (zd<=0){
            printf("YES\n");
            cout<<i<<" "<<ans.size()<<endl;         
            for (int j=0;j<ans.size();j++)
                cout<<ans[j].first<<" "<<ans[j].second+1<<endl;
            return 0;
        }
        int best=-1;
        for (int j=0;j<n;j++)
            if (p[j]*maxx>=zd*100 && !used[j]){
                if (best==-1 || dmg[j]>dmg[best])
                    best=j;                                 
            }
        if (best==-1) continue;
        used[best]=true;
        td+=dmg[best];
        ans.pb(mp(i,best));
        
    }
    printf("NO\n");
    return 0;
}