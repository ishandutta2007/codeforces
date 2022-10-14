#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> M >> N;
    pair<int, int> A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    int t1 = A[0].first;

    vector<pair<int, int>> diff;
    for (int i = 0; i < N; i++) {
        if (A[i].first == t1 || A[i].second == t1) continue;
        diff.emplace_back(A[i]);
    }

    if (diff.size() == 0) {
        cout << "YES\n";
        return 0;
    }

    int t2 = diff[0].first;
    bool can = true;
    for (auto i : diff) {
        if (i.first == t2 || i.second == t2) continue;
        can = false;
        break;
    }
    if (can) {
        cout << "YES\n";
        return 0;
    }

    can = true;
    t2 = diff[0].second;
    for (auto i : diff) {
        if (i.first == t2 || i.second == t2) continue;
        can = false;
        break;
    }
    if (can) {
        cout << "YES\n";
        return 0;
    }

    t1 = A[0].second;
    diff.clear();
    for (int i = 0; i < N; i++) {
        if (A[i].first == t1 || A[i].second == t1) continue;
        diff.emplace_back(A[i]);
    }
    if (diff.size() == 0) {
        cout << "YES\n";
        return 0;
    }

    t2 = diff[0].first;
    can = true;
    for (auto i : diff) {
        if (i.first == t2 || i.second == t2) continue;
        can = false;
        break;
    }
    if (can) {
        cout << "YES\n";
        return 0;
    }

    can = true;
    t2 = diff[0].second;
    for (auto i : diff) {
        if (i.first == t2 || i.second == t2) continue;
        can = false;
        break;
    }
    if (can) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    return 0;
}