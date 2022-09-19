#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, k, el, x;
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n >> k >> el;
        int cnt=0, ans=0;
        for (int i=2; i<=n; i++) {
            cin >> x;
            if (2*x>el) cnt++;
            else cnt=0;
            if (cnt>=k) {
                ans++;
            }
            el=x;
        }
        cout << ans << "\n";
    }

    return 0;
}
/*
1
16 2
1 1 0 0 1 0 0 1 1 0 0 0 0 0 1 1
*/