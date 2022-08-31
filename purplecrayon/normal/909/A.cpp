#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())

int main() {
    string a, b; cin >> a >> b;
    string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    string one = "";
    for (int i = 0; i < sz(a); i++) {
        one += a[i];
        string two = "";
        for (int j = 0; j < sz(b); j++) {
            two += b[j];
            ans = min(ans, one + two);
        }
    }
    cout << ans << '\n';
}