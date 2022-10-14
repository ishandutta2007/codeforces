#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int p[200005];

int par(int n) {
    return p[n] == n ? n : p[n] = par(p[n]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    int N; cin >> N;
    iota(p, p + N + 1, 0);
    int alpha[30] = {};

    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (!alpha[s[j] - 'a'] == 0) p[par(alpha[s[j] - 'a'])] = par(i);
            alpha[s[j] - 'a'] = i;
        }
    }

    map<int, int> mp;
    for (int i = 1; i <= N; i++) {
        mp[par(i)]++;
    }

    cout << mp.size() << "\n";

}