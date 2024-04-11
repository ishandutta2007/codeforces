#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int x, y;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int n; cin >> n;
            if (n) x = i, y = j;
        }
    } 
    cout << abs(x - 2) + abs(y - 2);
}