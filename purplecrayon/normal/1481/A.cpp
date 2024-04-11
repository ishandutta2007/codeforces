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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int x, y; cin >> x >> y;
    string s; cin >> s;

    int mx_x = 0, mx_y = 0, mn_x = 0, mn_y = 0;
    for (auto c : s){
        if (c == 'U') mx_y++;
        else if (c == 'D') mn_y--;
        else if (c == 'L') mn_x--;
        else mx_x++;
    }
    if (mn_x <= x && x <= mx_x && mn_y <= y && y <= mx_y) cout << yes;
    else cout << no;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}