#include <bits/stdc++.h>

using namespace std;
const int c=200006;
int w, n, db, t[c], pos;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, db=0, pos=1;
        for (int i=1; i<=n; i++) cin >> t[i];
        while(pos<=n) {
            db+=t[pos], pos++;
            if (!t[pos] && t[pos+1]) pos++;
            pos++;
            if (t[pos]) pos++;
        }
        cout << db << "\n";
    }
    return 0;
}