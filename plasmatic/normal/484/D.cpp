// ./d-kindergarten.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e6+1, LG = 20, TH = 7;
int N,
    A[MN], tb1[LG][MN], tb2[LG][MN];
ll dp[MN];

int sign(int k) {
    return (k > 0) - (k < 0);
}

int qrange(int l, int r) {
    int bit = __lg(r-l+1);
    return max(tb2[bit][l], tb2[bit][r-(1<<bit)+1]) - min(tb1[bit][l], tb1[bit][r-(1<<bit)+1]);
}

void trans(int j, int i) {
    dp[i] = max(dp[i], dp[j] + qrange(j+1, i));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (auto i = 1; i <= N; i++) {
        cin >> A[i];
        tb1[0][i] = tb2[0][i] = A[i];
    }
    for (auto i = 1; i < LG; i++) {
        int jmp = 1 << (i-1), end = N-(1<<i)+1;
        for (auto j = 1; j <= end; j++) {
            tb1[i][j] = min(tb1[i-1][j], tb1[i-1][j+jmp]);
            tb2[i][j] = max(tb2[i-1][j], tb2[i-1][j+jmp]);
        }
    }
    vector<int> care{1};
    int predir = sign(A[2]-A[1]);
    for (auto i = 3; i <= N; i++) {
        int dir = sign(A[i]-A[i-1]);
        if (dir != predir) 
            care.push_back(i);
        predir = dir;
    }
    if (care.back() != N)
        care.push_back(N);

    for (auto i = 1; i <= min(N, TH+1); i++)
        for (auto j = 0; j < i; j++)
            trans(j, i);
    int sz = care.size();
    for (auto i = 1; i < sz; i++) {
        for (auto j = max(1, care[i]-TH); j <= min(N, care[i]+TH); j++) {
            for (auto k = max(0, care[i-1]-TH); k <= min(N, care[i-1]+TH); k++) {
                if (k < j)
                    trans(k, j);
            }
        }
    }

    cout << dp[N] << '\n';

    return 0;
}