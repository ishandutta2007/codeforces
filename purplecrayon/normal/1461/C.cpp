#include "bits/stdc++.h"
using namespace std;

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

void solve(){
    int n, m; cin >> n >> m; 
    vector<int> a(n); for (auto& it : a) cin >> it, --it;
    int r=n-1;
    while (r >= 0 && a[r] == r) r--;
    double ans=1;
    while (m--){
        int a; double p; cin >> a >> p, --a;
        if (a >= r) ans *= double(1)-p;//, cerr << "H " << p << '\n';//, cerr << "h\n";
    }
    cout << (r<0?1:(double(1)-ans)) << '\n';

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; cout << fixed << setprecision(8);// << '\n';
    while (t--) solve(); 
}