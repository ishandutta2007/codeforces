#include <bits/stdc++.h>

using namespace std;

const int inf = 1000;

typedef pair<int, int> pii;
#define f first
#define s second

int q;
int dp[201][201][5][5];
pii rec[201][201][5][5];

void precompute() {
    for(int i = 0; i <= 200; i++) {
        for(int j = 0; j <= 200; j++) {
            if(i == 15 && j <= 13) {
                dp[i][j][4][2] = 1;
                rec[i][j][4][2] = {i, j};
            } else if(j == 15 && i <= 13) {
                dp[i][j][4][2] = -1;
                rec[i][j][4][2] = {i, j};
            } else if(i > 15 && i - j == 2) {
                dp[i][j][4][2] = 1;
                rec[i][j][4][2] = {i, j};
            } else if(j > 15 && j - i == 2) {
                dp[i][j][4][2] = -1;
                rec[i][j][4][2] = {i, j};
            } else {
                dp[i][j][4][2] = -inf;
            }

            dp[i][j][4][0] = -inf;
            dp[i][j][4][1] = -inf;
            dp[i][j][4][3] = -inf;
            dp[i][j][4][4] = -inf;

            if(i == 0 && j == 0) {
                dp[i][j][4][1] = 0;
                dp[i][j][4][3] = 0;
            }

            rec[i][j][4][0] = {0, 0};
            rec[i][j][4][1] = {0, 0};
            rec[i][j][4][3] = {0, 0};
            rec[i][j][4][4] = {0, 0};
        }
    }

    for(int k = 3; k >= 0; k--) {
        for(int l = 0; l <= 4; l++) {
            for(int i = 0; i <= 200; i++) {
                for(int j = 0; j <= 200; j++) {
                    if(l > k) {
                        dp[i][j][k][l] = -inf;
                        continue;
                    }

                    if(k - l == 3 || l == 3) {
                        if(i == 0 && j == 0) {
                            dp[i][j][k][l] = 0;
                            rec[i][j][k][l] = {0, 0};
                        } else {
                            dp[i][j][k][l] = -inf;
                        }
                        continue;
                    }

                    if(k - l > 3 || l > 3) {
                        dp[i][j][k][l] = -inf;
                        continue;
                    }

                    int tmp = -inf;

                    for(int b = 0; b <= 23; b++) {
                        if(i >= 25 && j >= b && dp[i - 25][j - b][k + 1][l + 1] + 1 > tmp) {
                            tmp = dp[i - 25][j - b][k + 1][l + 1] + 1;
                            rec[i][j][k][l] = {25, b};
                        }
                    }

                    for(int b = 0; b <= 23; b++) {
                        if(i >= b && j >= 25 && dp[i - b][j - 25][k + 1][l + 0] - 1 > tmp) {
                            tmp = dp[i - b][j - 25][k + 1][l + 0] - 1;
                            rec[i][j][k][l] = {b, 25};
                        }
                    }

                    for(int b = 26; b <= i; b++) {
                        if(j >= b - 2 && dp[i - b][j - (b - 2)][k + 1][l + 1] + 1 > tmp) {
                            tmp = dp[i - b][j - (b - 2)][k + 1][l + 1] + 1;
                            rec[i][j][k][l] = {b, b - 2};
                        }
                    }

                    for(int b = 26; b <= j; b++) {
                        if(i >= b - 2 && dp[i - (b - 2)][j - b][k + 1][l + 0] - 1 > tmp) {
                            tmp = dp[i - (b - 2)][j - b][k + 1][l + 0] - 1;
                            rec[i][j][k][l] = {b - 2, b};
                        }
                    }

                    dp[i][j][k][l] = tmp;
                }
            }
        }
    }
}

void answer(int a, int b) {
    if(dp[a][b][0][0] < -3) {
        cout << "Impossible" << endl;
        return;
    } else {

        int sets = 0;

        vector<pii> ans;

        int i = a, j = b, k = 0, l = 0;
        while(true) {
            if(dp[i][j][k][l] < -3)
                break;

            if(rec[i][j][k][l] == pii{0, 0})
                break;

            if(k == 5)
                assert(false);
    //            break;

            sets++;

            ans.push_back(rec[i][j][k][l]);

            int i1 = i, j1 = j;

            i -= rec[i1][j1][k][l].f;
            j -= rec[i1][j1][k][l].s;
            if(rec[i1][j1][k][l].f > rec[i1][j1][k][l].s)
                l++;
            k++;
        }

        cout << l << ":" << sets - l << "\n";

        for(pii p : ans) {
            cout << p.f << ":" << p.s << " ";
        }
        cout << "\n";
    }

    ////////// zakomentiraj:
//    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> q;

    precompute();

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        answer(a, b);
    }

    return 0;
}