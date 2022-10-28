#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    string timur = "Timur";
    sort(timur.begin(), timur.end());

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        sort(s.begin(), s.end());

        cout << (s == timur ? "YES" : "NO") << '\n';
    }
    return 0;
}