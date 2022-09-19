#include <bits/stdc++.h>

using namespace std;
int w;
bool v[302][302];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n, k;
        cin >> n >> k;
        for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) v[i][j]=0;
        if (k%n) cout << 2 << "\n";
        else cout << 0 << "\n";
        for (int j=0; j<=n; j++) for (int i=0; i<n; i++) if (k>0) v[i][(i+j)%n]=1, k--;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) cout << v[i][j];
            cout << "\n";
        }
    }
    return 0;
}