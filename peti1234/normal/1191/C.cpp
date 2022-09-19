#include <bits/stdc++.h>

using namespace std;
long long n, m, k, db=1, fi=1, t[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        t[i]--;
    }
    for (int i=2; i<=n; i++) {
        long long a=(t[fi]-fi+1)/k, b=(t[i]-fi+1)/k;
        if (a!=b) {
            db++;
            fi=i;
        }
    }
    cout << db << "\n";
    return 0;
}