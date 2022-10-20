#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            a[i]++;
        }
        if(s[i] == 'b') {
            if(i) a[i-1]++;
        }
        if(s[i] == 'c') {
            if(i > 1) a[i-2]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) if(a[i] == 3) ans++;
    map<char, int> mp;
    mp['a'] = 0;
    mp['b'] = 1;
    mp['c'] = 2;
    for(int i = 0; i < m; i++) {
        int pos;
        char c;
        cin >> pos >> c;
        pos--;
        int from, to;
        from = pos - mp[s[pos]];
        to = pos - mp[c];
        if(from >= 0) {
            a[from]--;
            if(a[from] == 2) ans--;
        }
        if(to >= 0) {
            a[to]++;
            if(a[to] == 3) ans++;
        }
        s[pos] = c;
        cout << ans << endl;
    }
    return 0;
}