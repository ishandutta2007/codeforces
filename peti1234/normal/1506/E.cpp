#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, el, t[c], a[c], b[c];
priority_queue<int> kis, nagy;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        el=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x!=el) {
                for (int j=el+1; j<x; j++) {
                    kis.push(-j), nagy.push(j);
                }
                el=x;
                a[i]=b[i]=x;
            } else {
                a[i]=-kis.top(), b[i]=nagy.top();
                kis.pop(), nagy.pop();
            }
        }
        for (int i=1; i<=n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        for (int i=1; i<=n; i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}