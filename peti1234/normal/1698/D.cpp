#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n;
    cin >> n;
    int kis=0, nagy=n, koz;
    while (nagy-kis>1) {
        koz=(nagy+kis)/2;
        cout << "? " << 1 << " " << koz << endl;
        int cnt=0;
        for (int i=1; i<=koz; i++) {
            int x;
            cin >> x;
            if (x<=koz) cnt++;
        }
        if (cnt%2) {
            nagy=koz;
        } else {
            kis=koz;
        }
    }
    cout.flush() << "! " << nagy << endl;
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