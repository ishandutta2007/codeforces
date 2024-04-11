#include <bits/stdc++.h>

using namespace std;
int w, n, db, ut;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> a >> b;
        db=0, ut=1;
        for (int i=0; i<n; i++) {
            if (b[i]=='1') {
                if (a[i]=='0') {
                    db++;
                } else {
                    if (ut%2==0 && a[i-1]=='1') {
                        db++;
                    } else if (i+1!=n && a[i+1]=='1') {
                        db++, ut+=4;
                    }
                }
            }
            ut/=2;
        }
        cout << db << "\n";
    }
    return 0;
}