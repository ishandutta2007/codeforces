//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s[8];
    for (int i = 0; i < 8; i++) cin >> s[i];
    bool mark[2][8];
    memset(mark, true, sizeof mark);
    bool found = false;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (s[i][j] == 'W') {
                mark[0][i] = mark[1][j] = false;
                found = true;
            }
    if (found)
        cout << count(mark[0], mark[0] + 8, true) + count(mark[1], mark[1] + 8, true) << '\n';
    else
        cout << 8 << '\n';
    return 0;
}