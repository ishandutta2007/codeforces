#include <bits/stdc++.h>


using namespace std;



int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i, n, l ,r, x, m;
    ios::sync_with_stdio(false);
    cin >> n;
    int sum = 0;
    for(i = 1; i <= n; i++) {
        cin >> x;
        sum += x;
    }
    cin >> m;
    while(m > 0) {
        m--;
        cin >> l >> r;
        if(sum <= r) {
            cout << max(sum, l);
            return 0;
        }
    }
    cout << -1;
   // cin.close();
   // cout.close();
    return 0;
}