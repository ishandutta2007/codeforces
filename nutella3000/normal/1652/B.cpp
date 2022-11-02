#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define mp make_pair
#define siz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb emplace_back


void run() {
    string s; cin >> s;
    int id = siz(s);
    vector<int> cnt(26);
    for (int i = siz(s)-1; i >= 0; --i) {
        if (!cnt[s[i] - 'a']) id = i;
        ++cnt[s[i] - 'a'];
    }
    for (int i = id; i < siz(s); ++i)
        cout << s[i];
    cout << endl;
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}