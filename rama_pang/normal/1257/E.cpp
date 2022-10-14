#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int A[200005], B[200005], C[200005];
int L[200005];
int N;
int memo[200005][5], vis[200005][5];

int dp(int n, int cur) {
    if (n > N) return 0;
    if (cur > 3) return 1e8;
    if (vis[n][cur]) return memo[n][cur];
    vis[n][cur] = 1;
    int &res = memo[n][cur] = 1e8;
    if (cur < 3) res = min(res, (L[n] != cur + 1) + dp(n + 1, cur + 1));
    if (cur < 2) res = min(res, (L[n] != cur + 2) + dp(n + 1, cur + 2));
    res = min(res, (L[n] != cur) + dp(n + 1, cur));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    N = a + b + c;
    
    vector<int> aaa(N);
    iota(aaa.begin(), aaa.end(), 1);
    srand(time(NULL));
    random_shuffle(aaa.begin(), aaa.end());

    for (int i = 1; i <= a; i++) {
        cin >> A[i];
        // A[i] = aaa.back(); aaa.pop_back();
        L[A[i]] = 1;
    }
    for (int i = 1; i <= b; i++) {
        cin >> B[i];
        // B[i] = aaa.back(); aaa.pop_back();
        L[B[i]] = 2;
    }
    for (int i = 1; i <= c; i++) {
        cin >> C[i];
        // C[i] = aaa.back(); aaa.pop_back();
        L[C[i]] = 3;
    }

    sort(A + 1, A + a + 1);
    sort(B + 1, B + b + 1);
    sort(C + 1, C + c + 1);

    cout << dp(1, 1) << "\n";    

}
/*

    1 3 5 7 || 2 4 6


    1 3 2 2 3 1


*/