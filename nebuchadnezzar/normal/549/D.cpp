#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 105;

int n, m;
int field[MAXN][MAXN];
int now[MAXN];
string s;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'W') {
                field[i][j] = 1;
            } else {
                field[i][j] = -1;
            }
        }
    }

    int ans = 0;

    /*
    for (int i = n - 1; i >= 0; --i) {
        bool already = false;
        for (int j = m - 1; j >= 0; --j) {
            int bal = 0;
            if (i == n - 1 || field[i + 1][j] != field[i][j]) {
                ++bal;
            }
            if (j == m - 1 || field[i][j + 1] != field[i][j]) {
                ++bal;
            }
            if (bal == 2 || (now[j] && already)) {
                //cerr << i << " " << j << endl;
                now[j] = field[i][j];
                ++ans;
                already = true;
            }
        }
    }*/

    
    for (int i = n - 1; i >= 0; --i) {
        //bool already = false;
        int add = 0;
        for (int j = m - 1; j >= 0; --j) {
            //cerr << "where: " << i << " " << j << " " << add << endl;
            if (i == n - 1 && j == m - 1) {
                ++ans;
                //cerr << i << " " << j << endl;
                add = field[i][j];
                continue;
            }
            if (i == n - 1) {
                if (field[i][j] != field[i][j + 1]) {
                    ++ans;
                    add = field[i][j] - field[i][j + 1];
                    //cerr << i << " " << j << endl;
                }
                continue;
            }
            if (j == m - 1) {
                if (field[i][j] != field[i + 1][j]) {
                    add = field[i][j] - field[i + 1][j];
                    ++ans;
                    //cerr << i << " " << j << endl;
                }
                continue;
            }
            if (field[i + 1][j] + add != field[i][j]) {
                add = field[i][j] - field[i + 1][j];
                ++ans;
                //cerr << i << " " << j << endl;
            }
        }
    }


    cout << ans << endl;

    return 0;
}