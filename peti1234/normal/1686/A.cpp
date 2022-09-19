#include <bits/stdc++.h>

using namespace std;
int w, n, sum, t[105];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sum+=t[i];
        }
        bool jo=0;
        for (int i=1; i<=n; i++) {
            if (t[i]*n==sum) jo=1;
        }
        cout << (jo ? "YES" : "NO") << "\n";
        sum=0;
    }
    return 0;
}