#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ord(1 << n), c(1 << n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {return s[i] < s[j];});
    int now = 0;
    c[ord[0]] = now;
    for (int i = 1; i < (1 << n); i++) {
        if (s[ord[i]] != s[ord[i - 1]]) {
            now++;
        }
        c[ord[i]] = now;
    }
    for (int i = 1; i <= n; i++) {
        vector<array<int, 3>> arr;
        for (auto to : ord) {
            arr.pb({c[to], c[to ^ (1 << (i - 1))], to});
        }
        sort(arr.begin(), arr.end());
        int now = 0;
        c[arr[0][2]] = now;
        for (int j = 1; j < arr.size(); j++) {
            if (arr[j][0] != arr[j - 1][0] || arr[j][1] != arr[j - 1][1]) {
                now++;
            }
            c[arr[j][2]] = now;
        }
    }
    int j = -1;
    for (int i = 0; i < (1 << n); i++) {
        if (c[i] == 0) {
            j = i;
        }
    }
    string t = "";
    for (int i = 0; i < (1 << n); i++) {
        t += s[i ^ j];
    }
    cout << t << endl;
    return 0;
}