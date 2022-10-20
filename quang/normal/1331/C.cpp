#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a;
    cin >> a;
    vector<int> ls;
    for (int i = 0; i < 6; i++) {
        ls.push_back(a % 2);
        a /= 2;
    }
    reverse(ls.begin(), ls.end());
    swap(ls[1], ls[5]);
    swap(ls[2], ls[3]);
    int res = 0;
    for (int u : ls) res = res * 2 + u;
        cout << res << endl;
    return 0;
}