#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;
 
set<int> pw, sec;
int Min = inf, sum = 0, d_sum = 0;
 
void add_pow(int num) {
    pw.emplace(num);
    sum += num;
    if (Min < num) {
        d_sum -= Min;
        d_sum += num;
        Min = *pw.upper_bound(Min);
    }
}
 
void rem_pow(int num) {
    sum -= num;
    pw.erase(num);
    if (Min <= num) {
        d_sum -= num;
        Min = *(--pw.lower_bound(Min));
        d_sum += Min;
    }
}
 
 
void solve() {
    int n;
    cin >> n;
 
    for(int i = 1;i <= n;i++) {
 
         //if (i == 8) cout << Min << " " << sum << " " << d_sum << endl;
 
 
        int t, x;
        cin >> t >> x;
        if (t == 0) {
            if (x > 0) {
                add_pow(x);
            }else 
                rem_pow(-x);
        }else {
            if (x > 0) {
                sec.emplace(x);
                add_pow(x);
                Min = *(--pw.lower_bound(Min));
                d_sum += Min;
            }else {
                sec.erase(-x);
 
                d_sum -= Min;
                if (sec.empty()) Min = inf;
                else Min = *(pw.upper_bound(Min));
                
                rem_pow(-x);
            }
        }
 
        int res = sum + d_sum;
        int Min1 = -inf;
        if (sec.size()) Min1 = *sec.begin();
 
        if (Min1 >= Min) {
            res -= Min1;
            if (pw.size() != sec.size())
                res += *(--pw.lower_bound(Min));
        }
 
        //if (i == 8) cout << Min << " " << sum << " " << d_sum << endl;
 
        cout << res << endl;
    }
}
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);
 
    solve();
}