#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

int x[1001], y[1001], a[1001], b[1001];
map < pair <int, int>, int > mp;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        mp[{a[i], b[i]}]++;
    }
    for(i = 1; i <= n; i++) {
        mp[{a[i], b[i]}]--;
        int val1 = x[1] + a[i], val2 = y[1] + b[i];
        for(j = 2; j <= n; j++) {
            if(mp[{val1 - x[j], val2 - y[j]}] > 0) {
                mp[{val1 - x[j], val2 - y[j]}]--;
            }
            else {
                break;
            }
        }
        if(j == n + 1) {
            cout << val1 << " " << val2 << "\n";
            return 0;
        }
        for(int p = 1; p < j; p++) {
            mp[{val1 - x[p], val2 - y[p]}]++;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}