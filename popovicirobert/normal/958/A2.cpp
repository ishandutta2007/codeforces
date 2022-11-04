#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 2000;
const int MAXM = 200;
const int B = 31;

char mat[MAXM + 1][MAXN + 1];
string str;

ull hsh2[MAXM + 1][MAXN + 1];
ull hsh1[MAXN + 1];

map <ull, int> mp;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> str;
        ull val = 0;
        for(auto it : str) {
            val = val * B + it - 'a' + 1;
        }
        hsh1[i] = val;
    }
    for(i = 1; i <= m; i++) {
        cin >> (mat[i] + 1);
    }
    ull pw = 1;
    for(i = 1; i < m; i++) {
        pw *= B;
    }
    for(i = 1; i <= m; i++) {
        ull val = 0;
        for(j = 1; j <= n; j++) {
            val = val * B + mat[i][j] - 'a' + 1;
            if(j >= m) {
                hsh2[i][j] = val;
                val -= pw * (mat[i][j - m + 1] - 'a' + 1);
            }
        }
    }
    for(i = 1; i + m <= n + 1; i++) {
        ull val = 0;
        for(j = i; j < i + m; j++) {
            val = val * pw + hsh1[j];
        }
        mp[val] = i;
    }
    for(i = 1; i + m <= n + 1; i++) {
        ull val = 0;
        for(j = 1; j <= m; j++) {
            val = val * pw + hsh2[j][i + m - 1];
        }
        if(mp[val] > 0) {
            cout << mp[val] << " " << i;
            return 0;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}