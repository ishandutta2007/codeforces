#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;




int main() {
#ifdef HOME
    // ifstream cin("A.in");
    // ofstream cout("A.out");
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> cells[2];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cells[(i + j) & 1].push_back({i, j});
        }
    }

    for (int i = 0; i < n * n; i++) {
        int col;
        cin >> col;

        if (col == 1) {
            if (cells[0].size()) {
                cout << 2 << " " << cells[0].back().first << " " << cells[0].back().second << endl;
                cells[0].pop_back();
            } else {
                cout << 3 << " " << cells[1].back().first << " " << cells[1].back().second << endl;
                cells[1].pop_back();
            }
        } else if (col == 2) {
            if (cells[1].size()) {
                cout << 1 << " " << cells[1].back().first << " " << cells[1].back().second << endl;
                cells[1].pop_back();
            } else {
                cout << 3 << " " << cells[0].back().first << " " << cells[0].back().second << endl;
                cells[0].pop_back();
            }
        } else if (col == 3) {
            if (cells[0].size()) {
                cout << 2 << " " << cells[0].back().first << " " << cells[0].back().second << endl;
                cells[0].pop_back();
            } else {
                cout << 1 << " " << cells[1].back().first << " " << cells[1].back().second << endl;
                cells[1].pop_back();
            }
        }
    }
    
    return 0;
}