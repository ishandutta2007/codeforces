#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        int answer = 10;
        for (int mask = 0; mask < (1 << 10); mask++) {
            bool bad = false;
            for (int i = 0; i < 10; i++) {
                if (mask & (1 << i)) {
                    if (str[i] == '0') {
                        bad = true;
                    }
                } else {
                    if (str[i] == '1') {
                        bad = true;
                    }
                }
            }
            if (bad) {
                continue;
            }

            vector<int> cnt(2, 5), score(2, 0);

            for (int i = 0; i < 10; i++) {
                cnt[i & 1]--;
                if (mask & (1 << i)) {
                    score[i & 1]++;
                }

                if (score[0] > score[1] + cnt[1] || score[1] > score[0] + cnt[0]) {
                    answer = min(answer, i + 1);
                    break;
                }
            }
        }

        cout << answer << "\n";
    }
    

    return 0;
}