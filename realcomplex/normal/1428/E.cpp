#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll f(ll a, ll k){
    ll low = a/k;
    ll f1 = a % k;
    ll sol = low * low * (k - f1) + (low + 1) * (low + 1) * f1;
    return sol;
}

const int N = (int)1e5 + 10;
ll c[N];
ll a[N];

int main(){
    fastIO;
    int n, k;
    cin >> n >> k;
    priority_queue<pii> cuts;
    ll sol = 0;
    ll gain;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        c[i] = 1;
        sol += a[i] * a[i];
        gain = f(a[i],c[i])-f(a[i],c[i]+1);
        cuts.push(mp(gain, i));
    }
    int bi;
    for(int cut = 0; cut < k-n;cut ++ ){
        sol -= cuts.top().fi;
        bi = cuts.top().se;
        cuts.pop();
        c[bi]++;
        gain = f(a[bi], c[bi])-f(a[bi],c[bi]+1);
        cuts.push(mp(gain, bi));
    }
    cout << sol << "\n";
    return 0;
}