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
const int MAXN = 55;

char field[MAXN][MAXN];
int n, m;
string s;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            field[i][j] = s[j];
        }
    }   

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            vector <char> v;
            v.puba(field[i][j]);
            v.puba(field[i][j + 1]);
            v.puba(field[i + 1][j]);
            v.puba(field[i + 1][j + 1]);
            sort(bend(v));
            if (v[0] == 'a' && v[1] == 'c' && v[2] == 'e' && v[3] == 'f') {
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}