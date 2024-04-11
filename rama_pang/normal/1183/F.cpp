#include <bits/stdc++.h>
using namespace std;

int main() {
    int TC; cin >> TC; while (TC--) {
        int N; cin >> N;
        set<int> A;
        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            A.emplace(a);
        }
        
        int ans = *A.rbegin();
        if (*A.rbegin() % 2 == 0 && *A.rbegin() % 3 == 0 && *A.rbegin() % 5 == 0) {
            if (A.count(*A.rbegin() / 2) && A.count(*A.rbegin() / 3) && A.count(*A.rbegin() / 5)) {
                ans = max(ans, *A.rbegin() / 2 + *A.rbegin() / 3 + *A.rbegin() / 5);
            }
        }

        set<int> tmp;
        int mx1 = *A.rbegin();
        for (auto i : A) {
            if (mx1 % i == 0) continue;
            tmp.emplace(i);
        }
        A = tmp; tmp.clear();
        int mx2 = (A.size())? *A.rbegin() : 0;
        for (auto i : A) {
            if (mx2 % i == 0) continue;
            tmp.emplace(i);
        }
        A = tmp;
        int mx3 = (A.size())? *A.rbegin() : 0;

        ans = max(ans, mx1 + mx2 + mx3);

        cout << ans << '\n';
    }
}