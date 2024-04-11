#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        cout << 2 << "\n";
        for (int i=1; i<=n; i+=2) {
            int s=i;
            while (s<=n) {
                cout << s << " ";
                s*=2;
            }
        }
        cout << "\n";
    }
    return 0;
}