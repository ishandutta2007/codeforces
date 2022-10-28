#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int q;
string s, t, a;

void solve(){
    cin >> s >> t >> q;
    a = s+t;

    int n = sz(a);
    for (auto& c : a) c = min(c, 'B'); //remove all C's

    vector<int> trail(n);
    int run = 0;
    for (int i = 0; i < n; i++) {
        run = (a[i] == 'A' ? run+1 : 0);
        trail[i] = run;
    }
    vector<int> ps(n);
    for (int i = 0; i < n; i++) {
        ps[i] = a[i] == 'B';
        if (i) ps[i] += ps[i-1];
    }

    while (q--) {
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2, --l1, --r1, --l2, --r2;
        l2 += sz(s), r2 += sz(s);

        int t1 = min(r1-l1+1, trail[r1]);
        int t2 = min(r2-l2+1, trail[r2]);
        int b1 = ps[r1]-(l1?ps[l1-1]:0);
        int b2 = ps[r2]-(l2?ps[l2-1]:0);

        if (b2 < b1){ cout << '0'; continue; }
        if ((b2-b1)&1){ cout << '0'; continue; }
        if (b1 == b2) {
            if (t1 >= t2 && (t1-t2)%3 == 0){ cout << '1'; continue; }
            else { cout << '0'; continue; }
        }
        if (!b1) {
            if (t1 > t2){ cout << '1'; continue; }
            else { cout << '0'; continue; }
        }
        if (b2 > b1) {
            if (t1 >= t2){ cout << '1'; continue; }
            else { cout << '0'; continue; }
        }
        cout << '0';
        continue;
    }
    cout << '\n';

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}