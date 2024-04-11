#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "A"

typedef long long ll;
typedef long double ld;


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    vector<pair<int,int> > a;
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        int k,b;
        cin >> k >> b;
        a.pb(mp(k,b));
    }

    sort(a.begin(),a.end());

    int ans = a.back().first+1;

    while (true){
        bool q = true;
        for (int i = 0; i < n; i++)
            if (ans - a[i].first <= 15 && (1<<(2*(ans - a[i].first))) < a[i].second){
                q = false;
            }
        if (q)
            break;
        ans++;
    }

    cout << ans << endl;

      
  return 0;
}