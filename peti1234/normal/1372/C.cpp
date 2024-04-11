#include <bits/stdc++.h>

using namespace std;
int w, n, r, j, jr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, r=0, j=0, jr=0;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            if (x!=i) r++;
            else if (r) j++;
            if (x!=i && j) jr++;
        }
        if (jr) cout << "2\n";
        else if (r) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}