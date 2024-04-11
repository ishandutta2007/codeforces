#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>> ans;
array<int, 1000005> A, B;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int maks = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a; maks = max(maks, a);
        A[a]++;
    }
    if (A[0] != 1) {
        cout << - 1 << "\n";
        return 0;
    }
    A[0] = 0;
    int x = -1;
    for (int i = 0; i <= maks; i++) {
        if (A[i] != 4 * i) {
            x = i;
            break;
        }
    }
    if (x == -1) {
        maks /= 2;
        cout << maks + maks + 1 << " " << maks + maks + 1 << "\n";
        cout << maks + 1 << " " << maks + 1 << "\n";
        return 0;
    }
    int loc = 1;
    vector<pair<int, int>> fact;
    while (loc <= N) {
        if (N % loc == 0) {
            fact.push_back({loc, N / loc});
        }
        loc++;
    }
    for (auto f : fact) {
        int y = f.first + f.second - x - maks;
        memset(B.begin(), 0, sizeof(B));
        for (int i = 1; i <= f.first; i++) {
            for (int j = 1; j <= f.second; j++) {
                int r = abs(x - i) + abs(y - j);
                B[r]++;
            }
        }
        B[0] = 0;
        if (A == B) {
            cout << f.first << " " << f.second << "\n";
            cout << x << " " << y << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
}

/*
x + y = R + C - maks
*/