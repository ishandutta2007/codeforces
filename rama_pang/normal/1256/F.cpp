#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int Q; cin >> Q; while (Q--) {
        int n; cin >> n;
        string s, t;
        cin >> s >> t;
        map<char, int> S, T;
        for (int i = 0; i < n; i++) S[s[i]]++, T[t[i]]++;
        if (S != T) {
            cout << "NO\n";
            continue;
        }
        bool ok = false;
        for (auto i : S) {
            if (i.second > 1) {
                ok = true;
            }
        }
        if (ok) {
            cout << "YES\n";
            continue;
        }

        int ns = 0, nt = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] > s[j]) ns++;
                if (t[i] > t[j]) nt++;
            }
        }
        if (ns % 2 != nt % 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}