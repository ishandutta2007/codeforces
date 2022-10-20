#include <bits/stdc++.h>

using namespace std;

struct Matrix {
    vector<vector<int>> a;
    int deltaN, deltaM;
    int deltaVal;
    int n;
    Matrix(int n) {
        this->n = n;
        a.assign(n, vector<int>(n, 0));
        deltaN = deltaM = deltaVal = 0;
    }

    void reverse(const Matrix &u, bool inRow) {
        if (inRow) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][u.a[i][j]] = j;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[u.a[i][j]][j] = i;
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<Matrix> ls(6, Matrix(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> ls[0].a[i][j];
                ls[0].a[i][j]--;
            }
        }
        for (int i = 1; i < ls.size(); i++) {
            ls[i].reverse(ls[i - 1], i % 2);
        }
        string s;
        cin >> s;
        int cur = 0;

        auto updateM = [&](int id, int delta) {
            ls[id].deltaM = (ls[id].deltaM + delta + n) % n;
        };

        auto updateN = [&](int id, int delta) {
            ls[id].deltaN = (ls[id].deltaN + delta + n) % n;
        };

        auto updateVal = [&](int id, int delta) {
            ls[id].deltaVal = (ls[id].deltaVal + delta + n) % n;
        };

        for (auto c : s) {
            if (c == 'R' || c == 'L') {
                int deltaVal = (c == 'R' ? 1 : -1);
                int deltaId = (cur % 2 == 1 ? -1 : 1);
                
                updateM((cur + deltaId * 0 + 6) % 6, -deltaVal);
                updateM((cur + deltaId * 5 + 6) % 6, -deltaVal);

                updateN((cur + deltaId * 2 + 6) % 6, -deltaVal);
                updateN((cur + deltaId * 3 + 6) % 6, -deltaVal);


                updateVal((cur + deltaId * 1 + 6) % 6, deltaVal);
                updateVal((cur + deltaId * 4 + 6) % 6, deltaVal);
            } else if (c == 'D' || c == 'U') {
                int deltaVal = (c == 'D' ? 1 : -1);
                int deltaId = (cur % 2 == 1 ? 1 : -1);
                
                updateN((cur + deltaId * 0 + 6) % 6, -deltaVal);
                updateN((cur + deltaId * 5 + 6) % 6, -deltaVal);

                updateM((cur + deltaId * 2 + 6) % 6, -deltaVal);
                updateM((cur + deltaId * 3 + 6) % 6, -deltaVal);


                updateVal((cur + deltaId * 1 + 6) % 6, deltaVal);
                updateVal((cur + deltaId * 4 + 6) % 6, deltaVal);
            } else if (c == 'I') {
                if (cur % 2 == 0) cur = (cur + 1) % 6;
                else cur = (cur + 5) % 6;
            } else if (c == 'C') {
                if (cur % 2 == 1) cur = (cur + 1) % 6;
                else cur = (cur + 5) % 6;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int ii = (i + ls[cur].deltaN) % n;
                int jj = (j + ls[cur].deltaM) % n;
                cout << (ls[cur].a[ii][jj] + ls[cur].deltaVal) % n + 1 << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}