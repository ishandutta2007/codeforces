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

    
    int n, k;
    cin >> n >> k;

    vector<vector<int>> color(n + 1, vector<int>(n + 1));
    int answer = 0;

    function<void(int, int, int)> Solve = [&](int l, int r, int col) {
        answer = max(answer, col);

        if (r - l + 1 <= k) {
            for (int i = l; i < r; i++) {
                for (int j = i + 1; j <= r; j++) {
                    color[i][j] = col;
                    // cerr << i << " " << j << " " << col << "\n";
                }
            }
            return;
        }

        int len = (r - l + 1) / k;
        int rem = (r - l + 1) % k;

        int left = l;
        for (int segm = 0; segm < k; segm++) {
            int right = left + len - 1 + (rem > segm);

            for (int i = left; i <= right; i++) {
                for (int j = right + 1; j <= r; j++) {
                    color[i][j] = col;
                    // cerr << i << " " << j << " " << col << "\n";
                }
            }

            Solve(left, right, col + 1);

            left = right + 1;
        }
    };

    Solve(1, n, 1);

    cout << answer << "\n";
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cout << color[i][j] << " ";
        }
    }

    return 0;
}