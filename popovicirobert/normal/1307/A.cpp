#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t, i, n, d;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {
        cin >> n >> d;

        vector <int> a(n + 1);
        for(i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(i = 2; i <= n; i++) {
            int cur = min(a[i], d / (i - 1));
            a[1] += cur;
            d -= cur * (i - 1);
        }
        cout << a[1] << "\n";
    }

    return 0;
}