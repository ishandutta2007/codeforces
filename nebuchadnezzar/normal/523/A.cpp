#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
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
int field[MAXN][MAXN], field2[MAXN][MAXN];

string os = ".*";

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '*') {
                field[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            field2[j][m - i - 1] = field[i][j];
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << field2[i][j];
        }
        cout << endl;
    }*/

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j * 2 < m; ++j) {
            swap(field2[i][j], field2[i][m - j - 1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < 2; ++k) {
            for (int j = 0; j < m; ++j) {
                cout << os[field2[i][j]] << os[field2[i][j]];
            }
            cout << endl;
        }
    }

    return 0;
}