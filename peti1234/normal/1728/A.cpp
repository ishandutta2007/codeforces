#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        int maxi=0, pos=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x>maxi) {
                pos=i;
                maxi=x;
            }
        }
        cout << pos << "\n";
    }
    return 0;
}