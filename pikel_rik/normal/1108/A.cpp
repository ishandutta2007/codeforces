#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int q;
    cin >> q;

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        cout << l1 << " ";
        if (l1 != l2)
            cout << l2 << "\n";
        else
            cout << r2 << "\n";
    }
    return 0;
}