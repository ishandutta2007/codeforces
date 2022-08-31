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

    int n, m;
    cin >> n >> m;

    vi color(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int done = -1;
        if (color[a] != 0) done = a;
        if (color[b] != 0) done = b;
        if (color[c] != 0) done = c;

        if (done == -1) {
            color[a] = 1;
            color[b] = 2;
            color[c] = 3;
        }
        else if (done == a) {
            if (color[a] == 1) {
                color[b] = 2;
                color[c] = 3;
            }
            else if (color[a] == 2) {
                color[b] = 1;
                color[c] = 3;
            }
            else {
                color[b] = 1;
                color[c] = 2;
            }
        }
        else if (done == b) {
            if (color[b] == 1) {
                color[a] = 2;
                color[c] = 3;
            }
            else if (color[b] == 2) {
                color[a] = 1;
                color[c] = 3;
            }
            else {
                color[a] = 1;
                color[c] = 2;
            }
        }
        else {
            if (color[c] == 1) {
                color[a] = 2;
                color[b] = 3;
            }
            else if (color[c] == 2) {
                color[a] = 1;
                color[b] = 3;
            }
            else {
                color[a] = 1;
                color[b] = 2;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << "\n";
    return 0;
}