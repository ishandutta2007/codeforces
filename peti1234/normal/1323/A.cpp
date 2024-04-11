#include <bits/stdc++.h>

using namespace std;
int w, n, e, sum;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> e, sum=e;
        for (int i=2; i<=n; i++) {
            int x; cin >> x;
            sum+=x;
        }
        if (n==1 && e%2) {
            cout << -1 << "\n";
        }
        else {
            if (e%2==0) {
                cout << "1\n1\n";
            } else if (sum%2==0) {
                cout << n << "\n";
                for (int i=1; i<=n; i++) cout << i << " ";
                cout << "\n";
            } else {
                cout << n-1 << "\n";
                for (int i=2; i<=n; i++) cout << i << " ";
                cout << "\n";
            }
        }
    }
    return 0;
}