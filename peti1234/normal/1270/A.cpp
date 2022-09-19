#include <bits/stdc++.h>

using namespace std;
int w, a, b, m1, m2;
int main()
{
    cin >> w;
    while(w--) {
        cin >> a >> a >> b, m1=0, m2=0;
        for (int i=1; i<=a; i++) {
            int x; cin >> x;
            m1=max(m1, x);
        }
        for (int i=1; i<=b; i++) {
            int x; cin >> x;
            m2=max(m2, x);
        }
        cout << (m1>m2 ? "YES" : "NO") << "\n";
    }
    return 0;
}