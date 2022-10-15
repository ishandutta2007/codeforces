#include <iostream>
#include <algorithm>

using namespace std;

int s, n;
pair<int,int> d[10000];

int main() {
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i].first >> d[i].second;
    }
    sort(&d[0], &d[n]);
    int v = 0;
    for (int i = 0; i < n; i++) {
        if (s > d[i].first) s += d[i].second;
        else v = 1;
    }
    if (v == 0) cout << "YES\n";
    else cout << "NO\n";
}