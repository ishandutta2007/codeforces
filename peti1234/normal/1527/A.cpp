#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        int n, po=1;
        cin >> n;
        while (2*po<=n) {
            po*=2;
        }
        cout << po-1 << "\n";
    }
    return 0;
}