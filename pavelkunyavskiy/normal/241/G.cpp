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




int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    
    int t = 320;

    vector<pair<int,int> > v;
    v.pb(mp(0,1000000));

    for (int i = 36000; t > 10; i++){
        bool ok = true;
        for (int j = 0; j < (int)v.size(); j++)      
            if ((v[j].first - i) * 1LL * (v[j].first - i) < 4LL * t *1LL* v[j].second)
                ok = false;
        if (ok){
            v.pb(mp(i,t));
            t--;
        }
    }

    int x = 10000;

    for (int i = v.back().first;;i++){
       if (i*1LL*i > 4LL*(x-10)*v[0].second)
          assert(false);
       bool ok = true;
       for (int j = 1; j < (int)v.size(); j++)
          if ((v[j].first - i) * 1LL * (v[j].first - i) < 4LL * x * 1LL*v[j].second)
            ok = false;

       if (!ok) continue;

       v.pb(mp(i,x));
       break; 
    }
    

    printf("%d\n",v.size());
    for (int i = 0; i < (int)v.size(); i++)
        printf("%d %d\n",v[i].first,v[i].second);
      
    return 0;
}