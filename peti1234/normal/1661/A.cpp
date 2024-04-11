#include <bits/stdc++.h>

using namespace std;
int w, n, a[30], b[30];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        long long sum=0;
        for (int i=1; i<=n; i++) {
            cin >> b[i];
            if (b[i]>a[i]) {
                swap(a[i], b[i]);
            }
            if (i>1) {
                sum+=abs(a[i]-a[i-1])+abs(b[i]-b[i-1]);
            }
        }
        cout << sum << "\n";
    }
    return 0;
}