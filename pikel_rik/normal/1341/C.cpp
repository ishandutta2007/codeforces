#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vi pos(n + 1);
        for (int i = 0; i < n; i++) pos[a[i]] = i;

        int ptr = pos[1];
        int flag = 0;

        int m = n;

        while (ptr < n and n > 1) {
            for (int i = ptr + 1; i < n; i++) {
                if (a[i] != a[i-1] + 1) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1)
                break;

            int temp = ptr;
            if (n >= 1 and a[n-1] + 1 <= m)
                ptr = pos[a[n-1] + 1];
            n = temp;
        }

        if (flag == 1)
            cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}