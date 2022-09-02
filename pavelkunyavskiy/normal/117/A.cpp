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

typedef long long ll;
typedef long double ld;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m;
    scanf("%d %d",&n,&m);

    for (int i = 0; i < n; i++){
        int from,to,t;
        scanf("%d %d %d",&from,&to,&t);

        --from,--to;


        if (from == to){
            printf("%d\n",t);
            continue;
        }


        vector<pair<int,int> > evs;

        int p = t / (2*m - 2);

        for (int i = -3; i <= 3; i++){
            evs.pb(mp((p+i)*(2*m-2) + from,0));
            evs.pb(mp((p+i)*(2*m-2) + 2*m-2 - from ,0));
            evs.pb(mp((p+i)*(2*m-2) + to,1));
            evs.pb(mp((p+i)*(2*m-2) + 2*m-2 - to, 1));
        }


        sort(evs.begin(),evs.end());

        bool good = false;

        for (int i = 0; i < evs.size(); i++)
            if (evs[i].first >= t){
                if (good && evs[i].second == 1){
                    printf("%d\n",evs[i].first);
                    break;
                }
                good |= (evs[i].second == 0);
            }
                                                         
    }

  return 0;
}