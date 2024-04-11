#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    set<int> pos;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) pos.insert(i);
    }

    int c = 0;
    for (int j = 0; j < m; j++) {
        int c1 = 0;
        set<int> temp;

        for (int i : pos) {
            if (a[i][j] > a[i-1][j])
                c1 += 1;
            else if (a[i][j] == a[i-1][j]) {
                temp.insert(i);
            }
        }

        if (c1 == pos.size()) break;

        if (c1 + temp.size() != pos.size()) {
            c += 1;
        }
        else if (c1 + temp.size() == pos.size()) {
            pos = temp;
        }
    }

    cout << c << "\n";
    return 0;
}