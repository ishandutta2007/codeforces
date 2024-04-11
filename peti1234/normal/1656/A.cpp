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
        int x, maxi, mini, np=1, kp=1;
        cin >> x;
        maxi=mini=x;
        for (int i=2; i<=n; i++) {
            cin >> x;
            if (x>maxi) {
                maxi=x;
                np=i;
            }
            if (x<mini) {
                mini=x;
                kp=i;
            }
        }
        cout << np << " " << kp << "\n";
    }
    return 0;
}