#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int a=0, b=0, n;
        cin >> n;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            if (!x) a++;
            else b++;
        }
        if (a>=n/2) {
            cout << a << "\n";
            for (int i=0; i<a; i++) cout << "0 ";
        } else {
            if (b%2) b--;
            cout << b << "\n";
            for (int i=0; i<b; i++) cout << "1 ";
        }
        cout << "\n";
    }
    return 0;
}