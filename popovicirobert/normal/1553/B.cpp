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
        bool answer = false;

        for (int l = 0; l < na && answer == false; l++) {
            int r = l, pos = 0;
            while (r < na && pos < nb && a[r] == b[pos]) {
                int i = pos, j = r;
                while (i < nb && j >= 0 && a[j] == b[i]) {
                    j--;
                    i++;
                }

                if (i == nb) {
                    answer = true;
                    break;
                }

                pos++;
                r++;
            }
        }

        cout << (answer ? "YES\n" : "NO\n");
    }
    

    return 0;
}