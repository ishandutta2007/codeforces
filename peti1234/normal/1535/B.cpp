#include <bits/stdc++.h>

using namespace std;
int w, n, t[2005], cnt;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        cnt=0;
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                if (max(__gcd(t[i], 2*t[j]), __gcd(2*t[i], t[j]))>1) {
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}