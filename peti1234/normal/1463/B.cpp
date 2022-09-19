#include <bits/stdc++.h>

using namespace std;
long long w, n, s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            int po=1;
            while(2*po<=x) {
                po*=2;
            }
            cout << po << " ";
        }
        cout << "\n";
    }
    return 0;
}