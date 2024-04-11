#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;

        int na = (int)a.size(), nb = (int)b.size();

        if (na < nb) {
            cout << "NO\n";
            continue;
        }

        int rem = (na - nb) % 2, pos = 0;
        // cerr << rem << "\n";
        for (int i = 0; i < na && pos < nb; i++) {
            if (i % 2 == rem && a[i] == b[pos]) {
                pos++;
                rem ^= 1;
            }
        }

        cout << (pos == nb ? "YES\n" : "NO\n");
    }
    

    return 0;
}