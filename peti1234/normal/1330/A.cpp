#include <bits/stdc++.h>

using namespace std;
int w, n, x, a;
bool v[202];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> x;
        for (int i=1; i<=n+x; i++) v[i]=false;
        for (int i=1; i<=n; i++) {
            cin >> a;
            v[a]=true;
        }
        for (int i=1; ; i++) {
            if (!v[i]) x--;
            if (x<0) {
                cout << i-1 << "\n";
                break;
            }
        }
    }
    return 0;
}
// Knny volt.