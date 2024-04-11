#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N;
vector<int> A;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<pair<int, int>> asc;
    for (int i = 0; i < N; i++) {
        int cur = i;
        while (i + 1 < N && A[i] < A[i + 1]) {
            i++;
        }
        asc.emplace_back(cur, i);
    }
    int ans = 0;
    for (int i = 0; i < asc.size(); i++) {
        ans = max(ans, asc[i].second - asc[i].first + 1);
        if (i + 1 < asc.size()) {
            if (asc[i].second + 1 == asc[i + 1].first) {
                if (asc[i].second - asc[i].first + 1 >= 2) {
                    if (asc[i + 1].second - asc[i + 1].first + 1 >= 2) {
                        if (A[asc[i].second - 1] < A[asc[i + 1].first]) {
                            ans = max(ans, asc[i + 1].second - asc[i].first);
                        } else if (A[asc[i].second] < A[asc[i + 1].first + 1]) {
                            ans = max(ans, asc[i + 1].second - asc[i].first);
                        }
                    } else {
                        if (A[asc[i].second - 1] < A[asc[i + 1].first]) {
                            ans = max(ans, asc[i + 1].second - asc[i].first);
                        }
                    }
                } else {
                    if (asc[i + 1].second - asc[i + 1].first + 1 >= 2) {
                        if (A[asc[i].second] < A[asc[i + 1].first + 1]) {
                            ans = max(ans, asc[i + 1].second - asc[i].first);
                        }
                    }
                }
            }
        }
        if (i + 2 < asc.size()) {
            if (asc[i].second + 2 == asc[i + 2].first) {
                if (A[asc[i].second] < A[asc[i + 2].first]) {
                    ans = max(ans, asc[i].second - asc[i].first + 1 + asc[i + 2].second - asc[i + 2].first + 1);
                }
            }
        }
    }
    
    cout << ans << "\n";

    return 0;
}