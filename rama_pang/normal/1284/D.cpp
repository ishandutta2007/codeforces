#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    vector<pair<pair<int, int>, int>> A(N), B(N);
    vector<int> st[2], et[2];

    for (int i = 0; i < N; i++) {
        cin >> A[i].first.first >> A[i].first.second >> B[i].first.first >> B[i].first.second;
        A[i].second = B[i].second = i;
        st[0].emplace_back(A[i].first.first);
        et[0].emplace_back(A[i].first.second);
        st[1].emplace_back(B[i].first.first);
        et[1].emplace_back(B[i].first.second);
        
    }
    // sort(begin(A), end(A));
    // sort(begin(B), end(B));
    sort(begin(st[0]), end(st[0]));
    sort(begin(et[0]), end(et[0]));
    sort(begin(st[1]), end(st[1]));
    sort(begin(et[1]), end(et[1]));
    vector<int> cntA(N), cntB(N);
    for (int i = 0; i < N; i++) {
        int l = prev(lower_bound(begin(et[0]), end(et[0]), A[i].first.first)) - begin(et[0]) + 1; // doesn't intersect if ending time < start[cur]
        int r = N - (upper_bound(begin(st[0]), end(st[0]), A[i].first.second) - begin(st[0])) + 1; // doesn't intersect if starting time > end[cur]
        cntA[i] = (N - l - r);
        
        l = prev(lower_bound(begin(et[1]), end(et[1]), B[i].first.first)) - begin(et[1]) + 1; // doesn't intersect if ending time < start[cur]
        r = N - (upper_bound(begin(st[1]), end(st[1]), B[i].first.second) - begin(st[1])) + 1; // doesn't intersect if starting time > end[cur]
        cntB[i] = (N - l - r);
        if (cntA[i] != cntB[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;

}