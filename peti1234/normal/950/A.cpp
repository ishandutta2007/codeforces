#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l, r, a;
    cin >> l >> r >> a;
    cout << 2*min({l+a, r+a, (a+l+r)/2}) << "\n";
    return 0;
}