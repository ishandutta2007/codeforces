#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,D;
    cin >> N >> D;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.rbegin(),A.rend());
    long long sum = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int now = D/A[i]+1;
        sum += now;
        if(sum <= N) {
            ans++;
        }
    }
    cout << ans << endl;
}