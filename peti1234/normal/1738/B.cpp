#include <bits/stdc++.h>

using namespace std;
long long n, k, t[100005];
void solve() {
    cin >> n >> k;
    for (int i=1; i<=k; i++) {
        cin >> t[i];
    }
    bool jo=1;
    for (int i=2; i<k; i++) {
        if (2*t[i]>t[i-1]+t[i+1]) {
            jo=0;
        }
    }
    long long s=n-k+1;
    if (k>=2 && t[1]*(s+1)>t[2]*s) {
        jo=0;
    }
    cout << (jo ? "Yes" : "No") << "\n";
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