#include<bits/stdc++.h>

using namespace std;
#define int long long
const int max_n = 104;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    int n;
    cin >> n;
    string c[]{"green", "yellow", "orange", "purple", "red", "blue"};
    string a[]{"Time", "Mind", "Soul", "Power", "Reality", "Space"};
    set<string> b;
    for(int i = 0;i < n;i++) {
        string s;
        cin >> s;
        b.emplace(s);
    }
    cout << 6 - n << '\n';
    for(int i = 0;i < 6;i++) {
        if (b.find(c[i]) == b.end()) cout << a[i] << '\n';
    }
}