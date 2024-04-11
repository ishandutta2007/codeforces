#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 1000;

bool a[MAXN + 1], b[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, s, x;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> s;
    for(i = 1; i <= n; i++) {
        cin >> x;
        a[i] = x;
    }
    for(i = 1; i <= n; i++) {
        cin >> x;
        b[i] = x;
    }
    if(a[1] == 0) {
        cout << "NO";
        return 0;
    }
    if(a[s] == 1) {
        cout << "YES";
        return 0;
    }
    if(b[s] == 0) {
        cout << "NO";
        return 0;
    }
    for(i = s; i <= n; i++) {
        if(a[i] == 1 && b[i] == 1) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}