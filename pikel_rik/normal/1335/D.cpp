#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        vector<string> s(9);
        for (int i = 0; i < 9; i++) cin >> s[i];

        if (s[0][0] != '1')
            s[0][0] = '1';
        else
            s[0][0] = '2';

        if (s[1][3] != '1')
            s[1][3] = '1';
        else
            s[1][3] = '2';

        if (s[2][6] != '1')
            s[2][6] = '1';
        else
            s[2][6] = '2';

        if (s[3][1] != '1')
            s[3][1] = '1';
        else
            s[3][1] = '2';

        if (s[4][4] != '1')
            s[4][4] = '1';
        else
            s[4][4] = '2';

        if (s[5][7] != '1')
            s[5][7] = '1';
        else
            s[5][7] = '2';

        if (s[6][2] != '1')
            s[6][2] = '1';
        else
            s[6][2] = '2';

        if (s[7][5] != '1')
            s[7][5] = '1';
        else
            s[7][5] = '2';

        if (s[8][8] != '1')
            s[8][8] = '1';
        else
            s[8][8] = '2';

        for (int i = 0; i < 9; i++) cout << s[i] << "\n";
    }
    return 0;
}