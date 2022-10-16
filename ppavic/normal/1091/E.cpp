#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>

#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair < ll, ll > pii;
typedef vector < ll > vi;
typedef set < ll > si;

const ll N = 1e6 + 500;
const ll M = 1e6 + 500;
const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const ll LOG = 20;
const ll OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;

ll gran1[N], gran2[N],  n, a[N], par, pref[N];
ll sum = 0, sum2 = 0;

ll get(ll l,ll r){
    if(l > r) return 0;
    return pref[r] - (l ? pref[l - 1] : 0);
}

ll binary(ll x,ll k){
    ll ret = -1;
    for(ll l = 18;l >= 0;l--){
        if(x + ret + (1 << l) >= n) continue;
        if(a[x + ret + (1 << l)] >= k) ret += (1 << l);
    }
    return x + ret + 1;
}

int main(){
    for(ll i = 0;i<N;i++){
        gran1[i] = 0, gran2[i] = INF * INF;
    }
    scanf("%d", &n);
    for(ll i = 0;i<n;i++){
        scanf("%d", a + i);
        pref[i] = a[i];
        sum += a[i];
        par = (par + a[i]) % 2;
    }
    pref[n] = pref[n - 1];
    sort(a, a + n);
    reverse(a, a + n);
    for(ll i = 0;i<n;i++){
        pref[i] = a[i];
        if(i) pref[i] += pref[i - 1];
    }
    ll j = n - 1;
    for(ll k = n;k>=1;k--){
        ll sum1 = get(0, k - 1);
        ll poz = binary(k, k);
        ll sum2 = (poz - k) * k + get(poz, n - 1);
        gran1[a[k - 1]] = max(sum1 - k * (k - 1) - sum2, gran1[a[k - 1]]); // >=
        gran2[a[k - 1]] = min((ll)k * (k - 1) - (sum1 - a[k - 1]) + sum2 + min(a[k - 1], (ll)k), (ll)gran2[a[k - 1]]);  // <=

    }
    for(ll i = 1;i<=n;i++){
        gran2[i] = min(gran2[i], gran2[i - 1]);
    }
    for(ll i = n - 1;i >= 0; i--){
        gran1[i] = max(gran1[i], gran1[i + 1]);
    }
    ll cnt = 0;
    for(int i = 0;i<=n;i++){
        if(i % 2 == par && gran1[i] <= i && i <= gran2[i])
            printf("%d ", i), cnt++;
    }
    if(cnt == 0) printf("-1");
    printf("\n");

    return 0;
}