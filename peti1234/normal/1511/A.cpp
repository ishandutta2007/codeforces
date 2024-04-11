#include <bits/stdc++.h>

using namespace std;
int w, n, x, cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        cnt=0;
        for (int i=1; i<=n; i++) {
            cin >> x;
            cnt+=(x!=2);
        }
        cout << cnt << "\n";
    }
    return 0;
}