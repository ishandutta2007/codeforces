#include <bits/stdc++.h>

using namespace std;
int w, n, a, b;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, a=0, b=0;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            if (x==1) a++;
            else b++;
        }
        if (a%2 || (a==0 && b%2)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}