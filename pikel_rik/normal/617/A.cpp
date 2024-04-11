#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    int m = 0;
    if (x % 5 == 0)
        m = x / 5;
    else
        m = x / 5 + 1;
    cout << m;

}