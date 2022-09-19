#include <bits/stdc++.h>

using namespace std;
bool v[2001];
bool id[2001];
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        int n, k;
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            if ((i%2==0 && i/2<k) || i>=n-n/2+k) {
                id[i]=1;
            } else {
                (id[i]=0);
            }
            char c;
            cin >> c;
            if (c=='(') {
                v[i]=false;
            } else {
                v[i]=true;
            }
        }
        cout << n << "\n";
        for (int i=1; i<=n; i++) {
            for (int j=i; j<=n; j++) {
                if (v[j]==id[i]) {
                    cout << i << " " << j << "\n";
                    swap(v[i], v[j]);
                    break;
                }
            }
        }
    }
    return 0;
}