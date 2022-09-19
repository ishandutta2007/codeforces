#include <bits/stdc++.h>

using namespace std;
int n, t[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n;
        int cnt=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (t[i]<0) cnt++;
        }
        for (int i=1; i<=n; i++) {
            if (i<=cnt && t[i]>0 || i>cnt && t[i]<0) t[i]*=-1;
        }
        cout << (is_sorted(t+1, t+n+1) ? "YES" : "NO") << "\n";
    }
    return 0;
}