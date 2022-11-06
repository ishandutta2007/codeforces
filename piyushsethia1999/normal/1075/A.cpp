#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    int x; cin >> x;
    int y; cin >> y;
    if (max(x - 1, y - 1) <= max(n - x, n - y))
        cout << "White";
    else
        cout << "Black";
}