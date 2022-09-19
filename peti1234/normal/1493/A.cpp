#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w, n, k;
    cin >> w;
    while (w--) {
        cin >> n >> k;
        int s=(k+1)/2;
        cout << n-k+k/2 << "\n";
        for (int i=s; i<k; i++) {
            cout << i << " ";
        }
        for (int i=k+1; i<=n; i++) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}