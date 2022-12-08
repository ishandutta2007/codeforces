
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <cstring>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
int solve();
 
int main() {
#ifdef PoDuReM
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#endif
    solve();
    return 0;
}
 
const int dd = (int)5e3 + 7;
 
unordered_map<string, int> D;
int n;
string F[dd], G[dd], A[dd], Op[dd], B[dd], ans;
 
int get(int i, int k) {
    for (int j = 0; j < n; ++j) {
        if (G[j] != "P")
            D[F[j]] = G[j][i] - '0';
        else {
            int a, b;
            if (A[j] == "?")
                a = k;
            else
                a = D[A[j]];
            if (B[j] == "?")
                b = k;
            else
                b = D[B[j]];
 
            if (Op[j] == "AND")
                D[F[j]] = a & b;
            else if (Op[j] == "OR")
                D[F[j]] = a | b;
            else
                D[F[j]] = a ^ b;
        }
    }
    int cur = 0;
    for (int j = 0; j < n; ++j)
        cur += D[F[j]];
    return cur;
}
 
int solve() {
    ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        F[i] = s;
        cin >> s >> s;
        if (s[0] == '0' || s[0] == '1')
            G[i] = s;
        else {
            G[i] = "P";
            A[i] = s;
            cin >> Op[i] >> B[i];
        }
    }
 
    string ans, ans2;
 
    for (int i = 0; i < m; ++i) {
        int O1 = get(i, 0), O2 = get(i, 1);
        if (O1 <= O2)
            ans += '0';
        else
            ans += '1';
        if (O1 >= O2)
            ans2 += '0';
        else
            ans2 += '1';
    }
    cout << ans << "\n" << ans2;
    return 0;
}