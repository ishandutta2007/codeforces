#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define mod 1000000007
#define pi acos(-1)
using namespace std;

long long n, lis[555][555], r, c;

bool verify() {
    long long refe = 0;
    for (int i = 0; i < n; i++) refe += lis[i][i];
    for (int i = 0; i < n; i++) {
        long long cur = 0;
        for (int j = 0; j < n; j++) cur += lis[i][j];
        if (cur != refe) return false;
    }
    for (int i = 0; i < n; i++) {
        long long cur = 0;
        for (int j = 0; j < n; j++) cur += lis[j][i];
        if (cur != refe) return false;
    }
    long long cur = 0;
    for (int i = 0; i < n; i++) cur += lis[i][n - 1 - i];
    return cur == refe;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> lis[i][j];
            if (lis[i][j] == 0) {
                r = i;
                c = j;
            }
        }
    if (n == 1) {
        cout << 1;
        return 0; 
    }
    long long s = 0;
    long long rr = (r == 0) ? 1 : 0;
    for (int i = 0; i < n; i++) s += lis[rr][i];
    for (int i = 0; i < n; i++) s -= lis[r][i];
    lis[r][c] = s;
    if (s < 1 || !verify()) cout << -1;
    else cout << s;
}