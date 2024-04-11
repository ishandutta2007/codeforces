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
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    vector <int> a(n + 1), b(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector <bool> vis(n + 1);
    int pos = 1;
    for(i = 1; i <= n; i++) {
        int cur = 0;
        if(vis[b[i]] == 0) {
            cur++;
            while(a[pos] != b[i]) {
                vis[a[pos]] = 1;
                pos++;
                cur++;
            }
            pos++;
        }
        cout << cur << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}