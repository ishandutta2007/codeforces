#include <bits/stdc++.h>

using namespace std;
int par[1<<16];
int main()
{
    ios_base::sync_with_stdio(false);
    int w, n, k;
    cin >> w;
    while (w--) {
        cin >> n >> k;
        if (n==4 && k==3) {
            cout << -1 << "\n";
        } else {
            for (int i=0; i<n; i++) {
                par[i]=n-i-1;
            }
            if (k!=n-1) {
                par[n-1]=k, par[k]=n-1;
                par[0]=n-1-k, par[n-1-k]=0;
            } else {
                par[n-1]=n-2, par[n-2]=n-1;
                par[0]=1, par[1]=0;
                par[1]=3, par[3]=1;
                par[0]=n-4, par[n-4]=0;
            }
            for (int i=0; i<n; i++) {
                if (i<par[i]) {
                    cout << i << " " << par[i] << "\n";
                }
            }
        }
    }
    return 0;
}