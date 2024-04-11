#include <bits/stdc++.h>

using namespace std;
int w, n, pos, t[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, pos=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=2; i<n; i++) if (t[i]>max(t[i-1], t[i+1])) pos=i;
        if (!pos) cout << "NO\n";
        else cout << "YES\n" << pos-1 << " " << pos << " " << pos+1 << "\n";
    }
    return 0;
}