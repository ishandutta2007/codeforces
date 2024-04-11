#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
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
        int n;
        string str;
        cin >> n >> str;

        int cnt = 0;
        string a, b;
        a.resize(n);
        b.resize(n);

        for (int i = 0; i < n; i++) {
            if (str[i] == '1') {
                a[i] = b[i] = '(';
            } else {
                cnt++;
                if (cnt & 1) {
                    a[i] = '(';
                    b[i] = ')';
                } else {
                    a[i] = ')';
                    b[i] = '(';
                }
            }
        }

        if (cnt & 1) {
            cout << "NO\n";
            continue;
        }

        int bal_a, bal_b;
        auto Check = [&]() -> bool {
           bal_a = bal_b = 0;

           bool bad = false;
            for (int i = 0; i < n; i++) {
                bal_a += (a[i] == '(' ? 1 : -1);
                bal_b += (b[i] == '(' ? 1 : -1);
                if (bal_a < 0) {
                    bad = true;
                }
                if (bal_b < 0) {
                    bad = true;
                } 
            }
            return bad;
        };

        bool bad = Check();
        assert(bal_a == bal_b);

        if ((bal_a & 1) || bad == true) {
            cout << "NO\n";
            continue;
        }

        cnt = bal_a / 2;
        int i = n - 1;
        while (i >= 0 && cnt > 0) {
            if (str[i] == '1') {
                assert(a[i] == '(' && b[i] == '(');
                a[i] = b[i] = ')';
                cnt--;
            }
            i--;
        }

        if (Check() == false) {
            cout << "YES\n";
            cout << a << "\n" << b << "\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}