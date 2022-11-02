#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio(false);
    int n,v;
    cin >> n >> v;
    if (v >= n - 1) cout << n - 1;
    else {
        cout << (n - v) * (n - v + 1) / 2 - 1 + v;
    }
}