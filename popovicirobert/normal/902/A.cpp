#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, a, b;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int x = 0;
    for(i = 1; i <= n; i++) {
        cin >> a >> b;
        if(a <= x) {
            x = max(x, b);
        }
    }
    if(x >= m) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    //cin.close();
    //cout.close();
    return 0;
}