#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    vector<pair<char, int>> compressed;
    for (char c : s) {
        if (compressed.empty() or compressed.back().first != c)
            compressed.emplace_back(c, 0);
        compressed.back().second++;
    }
    int len = compressed.size();

    
    if (len % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    int mid = len / 2;
    if (compressed[mid].second < 2) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; mid + i < len;  ++i)
        if (compressed[mid -i].first != compressed[mid+i].first or compressed[mid - i].second + compressed[mid+i].second < 3) {
            cout << 0 << endl;
            return 0;
        }
    cout << compressed[mid].second + 1 << endl;
}