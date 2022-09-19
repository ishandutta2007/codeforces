#include <bits/stdc++.h>

using namespace std;
const int c=100005;
bool pr[c];
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=2; i<c; i++) {
        if (!pr[i]) {
            for (int j=2*i; j<c; j+=i) {
                pr[j]=1;
            }
        }
    }
    int w, n;
    cin >> w;
    while (w--) {
        cin >> n;
        int sum=0, pid=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sum+=x;
            if (x%2) {
                pid=i;
            }
        }
        if (!pr[sum]) {
            cout << n-1 << "\n";
            for (int i=1; i<=n; i++) {
                if (i!=pid) {
                    cout << i << " ";
                }
            }
            cout << "\n";
        } else {
            cout << n << "\n";
            for (int i=1; i<=n; i++) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}