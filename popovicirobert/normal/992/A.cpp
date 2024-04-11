#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

map <int, int> fr;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    int ans = 0;
    for(i = 1; i <= n; i++) {
        int x;
        cin >> x;
        fr[x]++;
        if(fr[x] == 1 && x != 0) {
            ans++;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}