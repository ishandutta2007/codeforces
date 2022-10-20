#include <bits/stdc++.h>

using namespace std;

const int N = 100010;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    b = min(b, a + 1);
    cout << a + b + c + c << endl;
    return 0;
}