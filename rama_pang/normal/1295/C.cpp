#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int Tc;
    cin >> Tc;
    while (Tc--) {
        string S, T;
        cin >> S >> T;

        int ans = 0, ptr = 0;
        vector<vector<int>> nxt(S.size() + 2, vector<int>(26, -1));
        
        for (int a = 0; a < 26; a++) {
            for (int i = (int) S.size(); i >= 1; i--) {
                nxt[i][a] = nxt[i + 1][a];
                if (S[i - 1] == a + 'a') {
                    nxt[i][a] = i;
                }
            }
            nxt[0][a] = nxt[1][a];
            for (int i = 0; i <= S.size(); i++) {
                if (nxt[i][a] == i) {
                    nxt[i][a] = nxt[i + 1][a];
                }
            }
        }

        while (ptr < T.size()) {
            ans++;
            int last = ptr;
            int i = 0;
            while (i <= S.size()) {
                i = nxt[i][T[ptr] - 'a'];
                if (i == -1) break;
                ptr++;
            }
            if (last == ptr) {
                ans = -1;
                break;
            }
        }
        cout << ans << "\n";
    }

}