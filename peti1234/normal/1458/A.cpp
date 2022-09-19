#include <bits/stdc++.h>

using namespace std;
long long n, m, ans, s, x;
long long gcd(long long a, long long b) {
    if (a>b) swap(a, b);
    if (!a) return b;
    return gcd(a, b%a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin >> x;
    for (int i=2; i<=n; i++) {
        cin >> s;
        ans=gcd(ans, abs(s-x));
    }
    for (int i=1; i<=m; i++) {
        cin >> s;
        cout << gcd(ans, x+s) << " ";
    }
    return 0;
}