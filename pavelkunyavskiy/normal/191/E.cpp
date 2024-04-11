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

const int MAXN = 110000;

ll sum[MAXN];
ll vals[MAXN];
int tree[MAXN];
int a[MAXN];
ll k;
int n;
                              
void update(int v){
    for (;v <= n; v |= (v+1))
        tree[v]++;
}

int get(int v){
    int sum = 0;
    for (; v != -1; v = (v & (v+1))-1)
        sum += tree[v];
    return sum;
}

bool check(ll val){
    memset(tree,0,sizeof(tree));

    ll cnt = 0;

    int id = lower_bound(vals,vals+n+1,0) - vals;
    update(id);
    for (int i = 0; i < n; i++){
        int id = upper_bound(vals,vals+n+1,sum[i+1] - val) - vals - 1;
        cnt += get(id);                                
        id = lower_bound(vals,vals+n+1,sum[i+1]) - vals;
        update(id);
    }
    //cerr << cnt << endl;               
    return cnt >= k;
}






int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d",&n);
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        sum[i+1] = a[i] + sum[i];
    }
    memcpy(vals,sum,sizeof(vals));
    sort(vals,vals+n+1);

    //check(4);
    //return 0;

    ll l = -(1LL<<55);
    ll r = (1LL<<55);

    while (r-l > 1){
        ll mid = (l+r)/2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    cout << l << endl;

  return 0;
}