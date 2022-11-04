#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 115;

char str[MAXN + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int l1 = -1, c1, l2, c2;
    for(i = 1; i <= n; i++) {
        cin >> str[i] + 1;
        for(j = 1; j <= m; j++) {
            if(str[i][j] == 'B') {
                if(l1 == -1) {
                    l1 = i;
                    c1 = j;
                }
                l2 = i;
                c2 = j;
            }
        }
    }

    cout << (l1 + l2) / 2 << " " << (c1 + c2) / 2;
    //cin.close();
    //cout.close();
    return 0;
}