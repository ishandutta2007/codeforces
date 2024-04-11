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
        int n;
        cin >> n;

        vector<int> a(n + 1), diff(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            diff[i] = a[i] - a[i - 1];
        }

        bool answer = true;
        for (int i = 2; i <= n; i++) {
            if (diff[1] > 0 && diff[i] < 0) {
                int curr = min(diff[1], -diff[i]);
                diff[i] += curr;
                diff[1] -= curr;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (diff[i] < 0) {
                answer = false;
            }
        }

        cout << (answer ? "YES\n" : "NO\n");
    }
    
    return 0;
}