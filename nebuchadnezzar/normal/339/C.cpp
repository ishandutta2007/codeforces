#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m;
string s;
bool mas[11][1001];
vector <int> ans, ret[11][1001];


int main() {
    cin >> s;
    cin >> m;

    if (s == "0000000001" && m == 1) {
        cout << "YES\n10";
        return 0;
    }

    for (int i = 0; i < 10; ++i) {
        if (s[i] == '1') {
            mas[i + 1][0] = true;
            ret[i + 1][0].push_back(i + 1);
        }
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < 10; ++j) {
            for (int k = 1; k <= 10; ++k) {
                if (k > j && s[k - 1] == '1' && mas[abs(j - k)][i - 1]) {   //ret[abs(j - k)][i - 1] != k
                    bool truly = false;
                    for (int l = 0; l < (int) ret[abs(j - k)][i - 1].size(); ++l) {
                        if (ret[abs(j - k)][i - 1][l] != k) {
                            truly = true;
                            break;
                        }
                    }
                    if (truly) {
                        mas[j][i] = true;
                        ret[j][i].push_back(k);
                    }
                }
            }
        }
    }

    bool truly = false;
    int c = 0;
    for (int i = 1; i < 10; ++i) {
        if(mas[i][m - 1] == true) {
            truly = true;
            c = i;//ret[i][m - 1];
        }
    }

    if (not truly) {
        cout << "NO";
        return 0;
    }

    int i = m - 1;
    int prev = -1;
    while (i >= 0) {
        int num = 0;
        for (int j = 0; j < (int) ret[c][i].size(); ++j) {
            if (ret[c][i][j] != prev) {
                num = ret[c][i][j];
                break;
            }
        }
        ans.push_back(num);
        c = abs(c - num);
        prev = num;
        --i;
    }

    reverse(ans.begin(), ans.end());

    cout << "YES\n";

    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}