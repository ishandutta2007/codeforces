#include <bits/stdc++.h>

using namespace std;
long long w, n, k, po[62];
int main()
{
    ios_base::sync_with_stdio(false);
    po[0]=1;
    for (int i=1; i<=61; i++) {
        po[i]=po[i-1]*2;
    }
    cin >> w;
    while (w--) {
        cin >> n >> k;
        k--;
        if (n<=61 && k>=po[n-1]) {
            cout << -1 << "\n";
        } else {
            int el=0;
            for (int i=1; i<n; i++) {
                int ert=(n-i-1);
                if (ert>60 || po[ert]>k) {
                    cout << i << " ";
                    for (int j=i-1; j>el; j--) {
                        cout << j << " ";
                    }
                    el=i;
                } else {
                    k-=po[ert];
                }
            }
            for (int i=n; i>el; i--) {
                cout  << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}