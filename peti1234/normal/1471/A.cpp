#include <bits/stdc++.h>

using namespace std;
long long w, n, sum, x, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> x, sum=0, db=0;
        for (int i=1; i<=n; i++) {
            long long y; cin >> y;
            db+=(y+x-1)/x, sum+=y;
        }
        cout << (sum+x-1)/x << " " << db << "\n";
    }
    return 0;
}