#include <bits/stdc++.h>

using namespace std;
int w, n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k;
        if ((n%2 && k%2==0) || n<k || (k%2 && n%2==0 && n<2*k)) cout << "NO" << "\n";
        else {
            cout << "YES" << "\n";
            for (int i=1; i<=k-1; i++) {
                if (k%2 && n%2==0) cout << 2 << " ";
                else cout << 1 << " ";
            }
            if (k%2 && n%2==0) n-=2*k-2;
            else n-=k-1;
            cout << n << "\n";
        }
    }
    return 0;
}