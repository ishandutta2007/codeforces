#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 206
// 44

using namespace std;

const int MAXN = (int) 5e5;

int a[MAXN + 1];
string b;

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int n, i;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> b;
    b = " " + b;
    int l = -1e9, r = 1e9;
    for(i = 5; i <= n; i++) {
        int mn = min(a[i], min(a[i - 1], min(a[i - 2], min(a[i - 3], a[i - 4]))));
        int mx = max(a[i], max(a[i - 1], max(a[i - 2], max(a[i - 3], a[i - 4]))));
        if(b[i - 1] == '1' && b[i - 2] == '1' && b[i - 3] == '1' && b[i - 4] == '1' && b[i] == '0') {
            r = min(r, mn - 1);
        }
        else if(b[i - 1] == '0' && b[i - 2] == '0' && b[i - 3] == '0' && b[i - 4] == '0' && b[i] == '1') {
            l = max(l, mx + 1);
        }
    }
    cout << l << " " << r;
    //cin.close();
    //cout.close();
    return 0;
}