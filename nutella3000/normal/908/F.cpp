#include <bits/stdc++.h>
 
using namespace std;
 
//#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e15 + 7;
 
int res = 0;
 
pii f(vector<int> a, pii b) {
    int res1 = 0;
    a.emplace(a.begin(), b.fi);
    a.emplace_back(b.se);
    for(int i = 1;i < sz(a);i++) {
        chkmax(res1, a[i] - a[i - 1]);
    }


    if (b.fi < 0 && b.se > 1e10) {
        if (sz(a) == 2)  return mp(0, 0);
        return mp(a[sz(a) - 2] - a[1], a[sz(a) - 2] - a[1]);
    }

    int num2 = b.se - b.fi - res1;

    return mp(((b.fi < 0 || b.se > 1e10) ? num2 : b.se - b.fi), num2);
}

 
void solve() {
    int n;
    cin >> n;
    map<string, vector<int>> a;
 
    for(int i = 0;i < n;i++) {
        int v;
        string s;
        cin >> v >> s;
        a[s].emplace_back(v);
    }
 
    for(auto& b : a) {
        sort(all(b.se));
    }
    
    a["G"].emplace_back(2 * inf);

    int res = 0;

    int id1 = 0, id2 = 0;
    vector<int> a1, a2;
    int last = -inf;

    for(int i : a["G"]) {
        while(id1 < sz(a["B"]) && a["B"][id1] <= i) {
            a1.emplace_back(a["B"][id1++]);
        }
        while(id2 < sz(a["R"]) && a["R"][id2] <= i) {
            a2.emplace_back(a["R"][id2++]);
        }

        pii res1 = f(a1, mp(last, i)), res2 = f(a2, mp(last, i));
        res += min(res1.fi + res2.fi, res1.se + res2.se + res1.fi);

        a1.clear();
        a2.clear();
        last = i;
    }

    cout << res;
}
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    solve();
}