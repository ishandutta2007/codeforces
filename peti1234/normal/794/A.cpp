#include <bits/stdc++.h>

using namespace std;
int sum, k, a, b, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> k >> a >> b;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x; cin >>x;
        if (a<x && x<b) {
            sum++;
        }
    }
    cout << sum << "\n";
    return 0;
}