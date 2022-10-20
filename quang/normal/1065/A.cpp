#include <bits/stdc++.h>

using namespace std;

const int N = 100010;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        long long s, a, b, c;
        cin >> s >> a >> b >> c;
        long long num = s / c;
        long long res = num + b * (int)(num / a);
        cout << res << endl;
    }
    return 0;
}