#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, t[c];
void solve() {
    cin >> n;
    long long sum=0, spec=0;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<n; i++) {
        sum+=abs(t[i]-t[i+1]);
        if (t[i]>t[i+1]) spec+=t[i]-t[i+1];
    }
    cout << sum+abs(t[1]-spec) << "\n";

}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
3
10 4 7
*/