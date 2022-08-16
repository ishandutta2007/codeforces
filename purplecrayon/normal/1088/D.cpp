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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 1e6+10, MAXB = 30, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int qry(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int ans; cin >> ans;
    return ans;
}

void solve(){
    int v=qry(0, 0);
    int a=0, b=0;

    for (int i = MAXB-1; i >= 0; i--) {
        int a1=qry(a|(1ll<<i), b);
        int a2=qry(a, b|(1ll<<i));
        if (a1 == -1 && a2 == 1) a ^= 1ll<<i, b ^= 1ll<<i;
        else if (a1 == a2) {
            if (v == 1) a ^= 1ll<<i;
            else b ^= 1ll<<i;
            v = a1;
        }
    }
    cout << "! " << a << ' ' << b << endl;
} 
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}