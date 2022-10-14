#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    lint K, a, b, A[4][4] = {}, B[4][4] = {};
    cin >> K >> a >> b;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> B[i][j];
        }
    }
    
    lint ansA = 0, ansB = 0;
    bool startloop = false;
    lint vis[4][4] = {};
    lint loopA = 0, loopB = 0;
    lint loop_cnt = 0;

    while (K > 0) {
        // cout << "Debug: " << ansA << " " << ansB << " " << K << "\n";
        if (vis[a][b]) {
            if (!startloop) {
                startloop = true;
                loopA = 0;
                loopB = 0;
                loop_cnt = 0;
                memset(vis, 0, sizeof(vis));
            } else {
                lint cnt = K / loop_cnt;
                K -= cnt * loop_cnt;
                ansA += cnt * loopA;
                ansB += cnt * loopB;
                memset(vis, 0, sizeof(vis));
                startloop = false;
                loopA = loopB = loop_cnt = 0;
                continue;
            }
        }
        vis[a][b] = 1;
        if (a == (b + 1) - ((b == 3)? 3 : 0)) {
            loopA++;
            ansA++;
        }
        if (b == (a + 1) - ((a == 3)? 3 : 0)) {
            loopB++;
            ansB++;
        }
        if (startloop) {
            loop_cnt++;
        }
        tie(a, b) = tie(A[a][b], B[a][b]);
        K--;
    }    

    cout << ansA << " " << ansB << "\n";
}