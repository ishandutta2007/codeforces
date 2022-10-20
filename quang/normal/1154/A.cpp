#include <bits/stdc++.h>

using namespace std;

const int N = 100010;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a(4);
    for (int i = 0; i < 4; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int foo = a[2] - a[1];
    int x = (foo + a[0]) / 2;
    int y = (a[0] - foo) / 2;
    cout << x << ' ' << y << ' ' << a[3] - x - y << endl;
    return 0;
}