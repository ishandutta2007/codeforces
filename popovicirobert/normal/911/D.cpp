#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 1500;

int v[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, l, r, j, m;
    ios::sync_with_stdio(false);
    int ans = 0;
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        for(j = i - 1; j > 0; j--) {
            if(v[i] < v[j])
               ans++;
        }
    }
    ans %= 2;
    cin >> m;
    while(m > 0) {
        m--;
        cin >> l >> r;
        int x = (r - l + 1);
        if(((x * (x - 1)) / 2) % 2 == 0) {
            if(ans % 2 == 0)
               cout << "even";
            else
               cout << "odd";
        }
        else {
            if(ans % 2 == 1)
               cout << "even";
            else
               cout << "odd";
        }
        ans = (ans + (x * (x - 1)) / 2) % 2;
        cout << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}