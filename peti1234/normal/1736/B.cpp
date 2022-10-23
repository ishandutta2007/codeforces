#include <bits/stdc++.h>

using namespace std;
int t[100005];
long long lcm(long long a, long long b) {
    return a*b/__gcd(a, b);
}
void solve() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    bool jo=1;
    for (int i=2; i<n; i++) {
        long long a=t[i-1], b=t[i], c=t[i+1], ab=lcm(a, b), bc=lcm(b, c);
        if (__gcd(ab, bc)!=b) jo=0;
    }
    cout << (jo ? "YES" : "NO") << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}