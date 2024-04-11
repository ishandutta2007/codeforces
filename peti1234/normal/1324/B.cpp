#include <bits/stdc++.h>

using namespace std;
int w, n, jo, t[5002];
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, jo=0;
        for(int i=1; i<=n; i++) cin >> t[i];
        for (int i=1; i<=n; i++) {
            for (int j=i+2; j<=n; j++) {
                if (t[i]==t[j]) jo=1;
            }
        }
        if (jo) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}