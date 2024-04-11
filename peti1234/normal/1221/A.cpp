#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        int n;
        cin >> n;
        long long sum=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x<=2048) {
                sum+=x;
            }
        }
        if (sum>=2048) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    return 0;
}