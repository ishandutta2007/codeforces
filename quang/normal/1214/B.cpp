#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int b, g;
    cin >> b >> g;
    int n;
    cin >> n;
    vector<pair<int, int>> ls;
    for (int i = 0; i <= n; i++) {
        int bb = i;
        int gg = n - i;
        if (bb <= b && gg <= g) {
            ls.push_back({bb, gg});
        }
    }
    cout << ls.size() << endl;
    return 0;
}