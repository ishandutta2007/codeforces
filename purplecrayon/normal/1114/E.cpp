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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int tq=0;
bool qG(int x){
    tq++;
    cout << "> " << x << '\n'; cout.flush();
    int y; cin >> y; while (y == -1);
    return y;
}
ll qA(int i){
    tq++;
    cout << "? " << (i+1) << '\n'; cout.flush();
    int y; cin >> y; while (y == -1);
    return y;
}
void solve(){
    int n; cin >> n;
    const int mx = 1e9+1;
    ll lo=-1, hi=mx+1, mid=(lo+hi)/2;
    while (lo < mid && mid < hi){
        if (qG(mid)) lo=mid;
        else hi=mid;
        mid=(lo+hi)/2;
    }
    ll d=-1;
    vector<int> a(n); iota(a.begin(), a.end(), 0);
	shuffle(a.begin(), a.end(), rng);
    for (int i = 0; i < 60-tq && i < n; i++){
        ll c=qA(a[i]);
        d = (d == -1 ? hi-c : __gcd(d, hi-c));
    }
    ll x1 = hi-d*(n-1);
    cout << "! " << x1 << ' ' << d << '\n'; cout.flush();
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}