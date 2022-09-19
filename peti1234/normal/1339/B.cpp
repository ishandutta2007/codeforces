#include <bits/stdc++.h>

using namespace std;
int w, n;
int t[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> t[i];
        sort(t+1, t+n+1);
        for (int i=(n+1)/2; i>=1; i--) {
            cout << t[i] << " ";
            if (2*i!=n+1) cout << t[n+1-i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// Egy rendezs s egy kis gondolat kellett.