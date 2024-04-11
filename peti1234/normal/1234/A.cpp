#include <bits/stdc++.h>

using namespace std;
int w, n, sum, x;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> x;
            sum+=x;
        }
        cout << (sum+n-1)/n << "\n";
        sum=0;
    }
    return 0;
}