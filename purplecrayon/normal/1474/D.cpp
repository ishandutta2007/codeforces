#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e6+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    //the left most stone must be used a[0] times
    //if a[0] > a[1] -> bad because wont be able to use anymore
    //a[1] -= a[0]
    //
    //the prefix-difference array must be nondec (must be convex?)
    //+-+-+-
    //same parity is +, different parity is -
    //they all must be positive
    //how does swapping two elements change anything?
    //everything to the right of the same parity changes, and 
    int n; cin >> n;
    vector<ll> a(n); for (auto& it : a) cin >> it;
    vector<ll> b(n);
    ll sm[2]={};
    for (int i = 0; i < n; i++){
        sm[i&1] += a[i];
        b[i] = sm[i&1]-sm[i&1^1];
    }
    vector<bool> pre(n);
    for (int i = 0; i < n; i++){
        pre[i] = b[i] >= 0;
        if (i) pre[i] = pre[i]&&pre[i-1];
    }
    if (*min_element(b.begin(), b.end()) >= 0 && b[n-1] == 0){
        cout << yes;
        return;
    }
    ll mn[2]; fill(mn, mn+2, 1e18);
    for (int i = n-2; i >= 0; i--){
        bool bad=0;
        if ((i&1)==(n&1^1)){
            ll u=a[i], v=a[i+1];
            ll nv=b[n-1];
            nv -= 2*u, nv += 2*v;

            bad = bool(nv);
        } else {
            ll u=a[i], v=a[i+1];
            ll nv=b[n-1];
            nv += 2*u, nv -= 2*v;

            bad = bool(nv);
        }
        //everything to the right in my parity loses 2*u, and gains 2*v
        //everything to the right in his parity loses 2*v and gains 2*u
        if (i&&!pre[i-1]) bad=1;
        ll u=a[i], v=a[i+1];
        if (mn[i&1]-2*u+2*v < 0) bad=1;
        if (b[i]-u+v < 0) bad=1;

        mn[i&1] = min(mn[i&1], b[i]);
        if (mn[i&1^1]-2*v+2*u < 0) bad=1;
        if (!bad) { cout << yes; return; }
    }
    cout << no;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}