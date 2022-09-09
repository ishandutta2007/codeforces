#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define all(_x) _x.begin(), _x.end()
#define szof(_x) (int) _x.size()

using namespace std;
typedef long long LL;

int k;
char outp[6][27];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> k;

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 27; ++j) {
            outp[i][j] = ' ';
        }
    }

    for (int i = 1; i < 5; ++i) {
        outp[i][0] = outp[i][25] = '|';
    }
    for (int i = 1; i < 26; ++i) {
        outp[0][i] = outp[5][i] = '-';
    }
    outp[0][0] = outp[0][25] = outp[5][0] = outp[5][25] = '+';
    outp[1][26] = outp[4][26] = ')';

    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 25; ++j) {
            outp[i][j] = '.';
        }
    }

    for (int i = 0; i <= 34; ++i) {
        char now = '#';
        if (i < k) {
            now = 'O';
        }
        if (i == 0) {
            outp[1][1] = now;
        } else if (i == 1) {
            outp[2][1] = now;
        } else if (i == 2) {
            outp[3][1] = now;
        } else {
            if (i % 3 == 1) {
                outp[1][(i / 3) * 2 + 1] = now;
            } else if (i % 3 == 0) {
                outp[4][(i / 3 - 1) * 2 + 1] = now;
            } else {
                outp[2][(i / 3) * 2 + 1] = now;
            }
        }
    }

    outp[1][24] = 'D';
    outp[1][23] = outp[2][23] = outp[4][23] = '|';

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 27; ++j) {
            if (outp[i][j] != ' ') {
                cout << outp[i][j];
            }
        }
        if (i < 5) {
            cout << endl;
        }
    }
    return 0;
}