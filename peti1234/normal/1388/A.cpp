#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, n-=30;
        if (n<1) cout << "NO\n";
        else {
            cout << "YES\n";
            if (n==6 || n==10 || n==14) cout << 6 << " " << 10 << " " << 15 << " " << n-1 << "\n";
            else cout << 6 << " " << 10 << " " << 14 << " " << n << "\n";
        }
    }
    return 0;
}