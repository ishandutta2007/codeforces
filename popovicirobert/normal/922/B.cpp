#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 175
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    int ans = 0;
    for(i = 1; i <= n; i++) {
        for(j = i; j <= n; j++) {
            int k = (i ^ j);
            if(j <= k && k <= n && k > 0 && k < i + j)
                ans++;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}