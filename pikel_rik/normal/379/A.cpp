#include <bits/stdc++.h>
using namespace std;

int candles(int a, int b) {
    if (a < b)
        return a;
    return a - a%b + candles(a/b + a%b, b);
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << candles(a, b);
    return 0;
}