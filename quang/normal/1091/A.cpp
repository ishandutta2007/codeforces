#include <bits/stdc++.h>

using namespace std;

const int N = 100010;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    b--;
    c -= 2;
    int x = min(a, min(b, c));
    cout << x * 3 + 3 << endl;
    return 0;
}