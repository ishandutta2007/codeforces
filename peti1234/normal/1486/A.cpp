#include <bits/stdc++.h>

using namespace std;
long long w, n, sum=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n, sum=0;
        bool jo=1;
        for (long long i=0; i<n; i++) {
            int x; cin >> x;
            sum+=x;
            if (sum<(i*(i+1))/2) {
                jo=0;
            }
        }
        cout << (jo? "YES" : "NO") << "\n";
    }
    return 0;
}