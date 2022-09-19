#include <bits/stdc++.h>

using namespace std;
long long w, n, x, p=100000000000;
bool v[200002], r;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, r=0;
        for (int i=0; i<n; i++) v[i]=0;
        for (int i=1; i<=n; i++) {
            cin >> x;
            v[(x+i+p*n)%n]=true;
        }
        for (int i=0; i<n; i++) if (!v[i]) r=true;
        if (r) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
    return 0;
}