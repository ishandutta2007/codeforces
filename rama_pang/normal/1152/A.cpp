#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;
    int cntA[2] = {}, cntB[2] = {};
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        cntA[k % 2]++;
    }
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        cntB[k % 2]++;
    }
    int ans = 0;
    ans += min(cntA[0], cntB[1]);
    ans += min(cntA[1], cntB[0]);
    cout << ans << "\n";
    

}