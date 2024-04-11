#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<string> A(N); string tmp;
        for (int i = 0; i < N; i++) cin >> A[i];
        int ans = 0;
        map<string, int> mp;
        for (int i = 0; i < N; i++) mp[A[i]]++;
        while (true) {
            int mx = 0;
            for (auto i : mp) mx = max(mx, i.second);
            if (mx == 1) break;

            bool changed = false;
            for (int i = 0; i < N; i++) {
                if (mp[A[i]] == 1) continue;
                for (int j = 0; j < 4; j++) {
                    for (char k = '0'; k <= '9'; k++) {
                        tmp = A[i];
                        tmp[j] = k;
                        if (mp.count(tmp) == 0) {
                            mp[A[i]]--;
                            if (mp[A[i]] == 0) {
                                mp.erase(mp.find(A[i]));
                            }

                            A[i] = tmp;
                            changed = true;
                            ans++;
                            mp[A[i]]++;
                            
                        }
                        if (changed) break;
                    }
                    if (changed) break;
                }
                if (changed) break;
            }
        }

        cout << ans << "\n";
        for (int i = 0; i < N; i++) {
            cout << A[i] << "\n";
        }

    }

}