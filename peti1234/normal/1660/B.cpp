#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int a=0, b=0, n, x;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> x;
            if (x>b) b=x;
            if (b>a) swap(a, b);
        }
        cout << (b+1>=a ? "YES" : "NO") << "\n";
    }
    return 0;
}