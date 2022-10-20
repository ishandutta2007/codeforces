#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int k, n1, n2 ,n3, t1, t2, t3, res;
int need1[1010], need2[1010], need3[1010];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    for(int i = 0; i < k; i++) {
        int Need = 0;
        Need = max(Need, need1[i % n1] + t1 + t2 + t3);
        Need = max(Need, need2[i % n2] + t2 + t3);
        Need = max(Need, need3[i % n3] + t3);
        res = max(res, Need);
        need1[i % n1] = Need - t2 - t3;
        need2[i % n2] = Need - t3;
        need3[i % n3] = Need;
    }
    cout << res;
    return 0;
}