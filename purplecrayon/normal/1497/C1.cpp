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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
 
void solve(){
    //start with n ones, then i can merg
    //k = 3
    //n/3, n/3, n/3
    //
    ll n; int k; cin >> n >> k;
    if (n%2 == 0){
        if (n%3 == 0){ cout << n/3 << ' ' << n/3 << ' ' << n/3 << '\n'; }
        else {
            if (n%4 == 0){ cout << n/4 << ' ' << n/4 << ' ' << n/2 << '\n'; }
            else cout << 2 << ' ' << (n-2)/2 << ' ' << (n-2)/2 << '\n';
        }
    } else {
        cout << 1 << ' ' << (n-1)/2 << ' ' << (n-1)/2 << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}