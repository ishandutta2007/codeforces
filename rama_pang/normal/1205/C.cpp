#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    auto isPalindrome = [](int r1, int c1, int r2, int c2) {
        r1++, c1++, r2++, c2++;
        cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
        int res;
        cin >> res;
        if (res == -1) {
            exit(0);
        }
        return res;
    };

    vector<vector<int>> grid(n, vector<int>(n, -1));
    grid[0][0] = 1;
    grid[0][1] = 1;
    grid[n - 1][n - 1] = 0;

    for (int rep = 0; rep < n * n + 100; rep++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1) {
                    if (j + 2 < n && grid[i][j + 2] == -1) {
                        grid[i][j + 2] = (isPalindrome(i, j, i, j + 2) ? grid[i][j] : (grid[i][j] ^ 1));
                    }
                    if (i + 1 < n && j + 1 < n && grid[i + 1][j + 1] == -1) {
                        grid[i + 1][j + 1] = (isPalindrome(i, j, i + 1, j + 1) ? grid[i][j] : (grid[i][j] ^ 1));
                    }
                    if (i + 2 < n && grid[i + 2][j] == -1) {
                        grid[i + 2][j] = (isPalindrome(i, j, i + 2, j) ? grid[i][j] : (grid[i][j] ^ 1));
                    }
                    if (j - 2 >= 0 && grid[i][j - 2] == -1) {
                        grid[i][j - 2] = (isPalindrome(i, j - 2, i, j) ? grid[i][j] : (grid[i][j] ^ 1));
                    }
                    if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == -1) {
                        grid[i - 1][j - 1] = (isPalindrome(i - 1, j - 1, i, j) ? grid[i][j] : (grid[i][j] ^ 1));
                    }
                    if (i - 2 >= 0 && grid[i - 2][j] == -1) {
                        grid[i - 2][j] = (isPalindrome(i - 2, j, i, j) ? grid[i][j] : (grid[i][j] ^ 1));
                    }
                }   
            }
        }
    }
    
    
    /* merge grid and grid - query length 4

        Let cells be c1, c2, c3, c4

        c1 == c3 && c2 == c4
            if palindrome:
                c2 = c4 = c1 = c3
            else:
                c2 = c4 = c1 ^ 1 = c3 ^ 1
        c1 != c3 && c2 != c4
            if palindrome:
                c2 = c3, c4 = c1
            else:
                c2 = c1, c4 =c 3
        
        So just ask 2 questions: c1 == c3 and c1 != c3, when c1 ^ c2 ^ c3 ^ c4 == 0

        Then we can find c2 and c4
    */

    int same = -1;
    vector<pair<int, int>> path;
    path.emplace_back(0, 0);
    for (int i = 1; i < n; i++) {
        path.emplace_back(0, i);
    }
    for (int i = 1; i < n; i++) {
        path.emplace_back(i, n - 1);
    }

    for (int i = 0; i + 3 < path.size(); i++) {
        int X = 0;
        vector<pair<int, int>> A(path.begin() + i, path.begin() + i + 4);
        for (auto i : A) {
            X ^= grid[i.first][i.second];
        }
        if (X == 0) {
            int ask = isPalindrome(A.front().first, A.front().second, A.back().first, A.back().second);
            if (ask == 1) {
                if (grid[A[1].first][A[1].second] == grid[A[2].first][A[2].second]) {
                    same = 1;
                } else {
                    same = 0;
                }
            }  else {
                if (grid[A[1].first][A[1].second] == grid[A[2].first][A[2].second]) {
                    same = 0;
                } else {
                    same = 1;
                }
            }
            break;
        }
    }

    if (same == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i + j) % 2 == 1) {
                    grid[i][j] ^= 1;
                }
            }
        }
    }

    cout << "!" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}