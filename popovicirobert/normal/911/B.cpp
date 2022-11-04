#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 1e3;

int v[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, a, b;
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    for(i = 1; i <= min(a, b) + 1; i++) {
        if(a / i + b / i < n || a / i == 0 || b / i == 0) {
            cout << i - 1;
            return 0;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}