#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, k, s, p;
    ios::sync_with_stdio(false);
    cin >> k >> n >> s >> p;
    cout << (k * ((n + s - 1) / s) + p - 1) / p;
    //cin.close();
    //cout.close();
    return 0;
}