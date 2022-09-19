#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n, m, sum=0;
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            sum+=x;
        }
        if (m==sum) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}