#include <bits/stdc++.h>

using namespace std;
int w, n, m, ma, mb, sum;
int main()
{
    cin >> w;
    while(w--) {
        ma=0, mb=0;
        cin >> n, sum=0;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            sum+=x;
            ma=max(ma, sum);
        }
        cin >> m, sum=0;
        for (int i=1; i<=m; i++) {
            int x; cin >> x;
            sum+=x;
            mb=max(mb, sum);
        }
        cout << ma+mb << "\n";
    }
    return 0;
}