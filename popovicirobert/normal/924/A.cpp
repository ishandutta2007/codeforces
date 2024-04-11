#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 50;
const int B = 31;

char mat[MAXN + 1][MAXN + 1];

int sef[MAXN + 1];

int myfind(int x) {
    if(sef[x] == 0)
        return x;
    return sef[x] = myfind(sef[x]);
}

inline void myunion(int x, int y) {
    x = myfind(x), y = myfind(y);
    if(x != y) {
        sef[x] = y;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> (mat[i] + 1);
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                if(mat[i][k] == mat[j][k] && mat[i][k] == '#') {
                    myunion(i, j);
                    break;
                }
            }
        }
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(mat[i][j] != mat[myfind(i)][j]) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    //cin.close();
    //cout.close();
    return 0;
}