#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>
 
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
 
#define oo            (int)13e7
#define s(n)          scanf("%d",&n)
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define ull           unsigned long long
#define ll            long long
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;

const ll lim = 100000000000LL;
vector<ll> sol;
void gen(ll x) {
    if (x > lim) return;
    if (x) sol.pb(x);
    gen(x*10 + 4);
    gen(x*10 + 7);
}

int main(int argc, char** argv)
{
	gen(0);
    
    sort(all(sol));
    ll lo, hi;
    cin>>lo>>hi;
    ll ans = 0;
    for (int i=0; i < sol.size(); i++) {
        if (sol[i] >= lo) {
            ll upper = min(sol[i], hi);
            ans += (upper - lo + 1) * sol[i];
            lo = upper + 1;
        }
        if (lo > hi) break;
    }
    cout << ans << endl;
	return 0;
}