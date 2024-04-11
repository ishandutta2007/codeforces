#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9;

bool _less(string& a, string& b) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }
    return false;
}

string OR(string& a, string& b) {
    string c = a;
    for (int i = 0; i < a.size(); ++i) {
        if (i+1 <= b.size() && b[b.size() - (i+1)] == '1') c[a.size() - (i+1)] = '1';
    }
    return c;
}

void run() {
    int n; string s;
    cin >> n >> s;

    string res = s;
    int id = s.find('0', s.find('1')) == s.npos ? 0 : s.find('0', s.find('1'));

    string t = s;
    for (int i = 0; i < id; ++i)
        t[i] = '0';
    for (int i = id; i >= 0; --i) {
        t[i] = s[i];

        auto q = OR(s, t);
        if (_less(res, q)) res = q;

        t.pop_back();
    }

    id = res.find('1');
    if (id == res.npos) id = res.size();
    for (int i = min((int)res.size()-1, id); i < res.size(); ++i)
        cout << res[i];
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        run();
    }
}