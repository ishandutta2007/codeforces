#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n, sum=0;
        cin >> n;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            sum+=x;
        }
        cout << (sum%n ? 1 : 0) << "\n";
    }
    return 0;
}