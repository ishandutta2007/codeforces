#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

int a[MAXN + 1], b[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> b[i];
    }
    map <int, int> fr;
    for(i = 1; i < n; i++) {
        fr[a[i + 1] - a[i]]++;
        fr[b[i + 1] - b[i]]--;
    }
    for(auto it : fr) {
        if(it.second) {
            cout << "No";
            return 0;
        }
    }
    if(a[1] != b[1] || a[n] != b[n]) {
        cout << "No";
        return 0;
    }
    cout << "Yes";
    //cin.close();
    //cout.close();
    return 0;
}