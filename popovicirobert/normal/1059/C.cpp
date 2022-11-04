#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e6;

void solve(int n, int pw) {
    if(n == 1) {
        cout << pw << " ";
        return ;
    }
    if(n == 2) {
        cout << pw << " " << 2 * pw << " ";
        return ;
    }
    if(n == 3) {
        cout << pw << " " << pw << " " << 3 * pw << " ";
        return ;
    }
    for(int i = 1; i <= n; i += 2) {
        cout << pw << " ";
    }
    solve(n / 2, pw * 2);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    solve(n, 1);
    //cin.close();
    //cout.close();
    return 0;
}