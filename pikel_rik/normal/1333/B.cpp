#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        vi a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        if (a[0] != b[0])
            cout << "NO\n";
        else {
            int pos1 = -1, pos2 = -1;
            for (int i = 0; i < n; i++) {
                if (pos1 == -1 and a[i] == 1)
                    pos1 = i;
                if (pos2 == -1 and a[i] == -1)
                    pos2 = i;
            }

            int flag = 0;
            for (int i = n - 1; i >= 1; i--) {
                if (b[i] > a[i] and (pos1 >= i or pos1 == -1)) {
                    flag = 1;
                    break;
                }
                if (b[i] < a[i] and (pos2 >= i or pos2 == -1)) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }

    return 0;
}