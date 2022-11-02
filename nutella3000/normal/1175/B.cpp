#include <bits/stdc++.h>
using namespace std;

#define long long long
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    long ans = 0;
    long it = 1;
    stack<int> a;
    int id = 0;
    for(int i = 0;i < n;i++) {
        string s;
        cin >> s;
        if (s == "add") {
            ans += it;
        }
        if (s == "end") {
            if (a.size() - 1 < id) {
                it /= a.top();
                id--;
            }
            a.pop();
        }
        if (s == "for") {
            int x;
            cin >> x;
            if (it < 1e10) {
                it *= x;
                id++;
            }
            a.push(x);
        }
        if (ans > (1ll << 32) - 1) {
            cout << "OVERFLOW!!!";
            return 0;
        }
    }
    cout << ans;
}