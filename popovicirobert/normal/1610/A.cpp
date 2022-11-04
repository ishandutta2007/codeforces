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
        int n, m;
        cin >> n >> m;

        if (max(n, m) == 1) {
            cout << 0 << "\n";
        } else if (min(n, m) == 1) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
    

   
    return 0;
}