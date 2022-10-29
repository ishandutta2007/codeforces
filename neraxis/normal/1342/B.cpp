#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        string t;
        cin >> t;
        bool ok = 0;
        for (int i = 1; i < t.size(); i++) if (t[i] != t[i - 1]) ok = 1;
        if (!ok) cout << t;
        else for (int i = 0; i < t.size(); i++) cout << "01";
        cout << '\n';
    }
    return 0;
}