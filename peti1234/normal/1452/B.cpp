#include <bits/stdc++.h>

using namespace std;
long long w, n, maxi, sum, x, cel, mar;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, maxi=0, sum=0;
        for (int i=1; i<=n; i++) {
            cin >> x;
            maxi=max(maxi, x);
            sum+=x;
        }
        cel=maxi*(n-1);
        mar=sum%(n-1);
        if (sum>=cel) {
            if (mar) cout << n-1-mar;
            else cout << 0;
        } else {
            cout << cel-sum;
        }
        cout << "\n";
    }
    return 0;
}