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


vector<ll> a;

const ll MAXN = 10000000000LL;


void gen(ll cur){
    if (cur > MAXN)
        return;
    a.pb(cur);
    gen(10*cur+4);
    gen(10*cur+7);
}


ll intersec(ll a,ll b,ll c,ll d){
//  cerr << a <<" "<<b<<" "<<c<<" "<<d <<" "<<max(0LL, min(b,d) - max(a,c)+1)<<endl;
    return max(0LL, min(b,d) - max(a,c)+1);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    gen(0);
    sort(a.begin(),a.end());

    int l,r;

    cin >> l >> r;

    ll ans = 0;

    for (int i = 1; i < a.size(); i++){
        ans += a[i] * intersec(a[i-1]+1,a[i],l,r);
//      cerr << ans << endl;
    }

    cout << ans << endl;
    return 0;
}