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

int need;
int n;
map<int,int> on,off;

int& sget(map<int,int>& a,int b){
    if (a.find(b) != a.end())
        return a[b];
    return (a[b] = 0);
}


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d",&n);
    need = (n+1)/2;

    for (int i = 0; i < n; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        sget(on,a)++;
        if (a != b)
            sget(off,b)++;
    }

    int ans = 1<<30;

    for (map<int,int>::iterator iter = on.begin(); iter != on.end(); ++iter){
        if (iter->second + sget(off,iter->first) >= need) {
            ans = min(ans, max(0,need - iter->second));
        }
    }

    for (map<int,int>::iterator iter = off.begin(); iter != off.end(); ++iter){
        if (iter->second >= need)
            ans = min(ans, need);
    }

    if (ans == (1<<30))
        cout << -1 << endl;
    else
        cout << ans << endl;


      
  return 0;
}