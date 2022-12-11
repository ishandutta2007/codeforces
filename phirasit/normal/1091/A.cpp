#include <bits/stdc++.h>

using namespace std;

int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int x = min(a, min(b-1, c-2));

    cout << (3 * x + 3) << endl;

    return 0;
}