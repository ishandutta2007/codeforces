#include <bits/stdc++.h>

using namespace std;

const int N = 85;
const int INF = 1e9;

int n;
vector<int> a;
int f[2][N * 2][N * N];
int sum[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    a.push_back(0);
    int last = 0;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        if (u == 1) {
            a.push_back(i - last - 1);
            last = i;
        }
    }
    a.push_back(n - last);
    sum[0] = 0;
    for (int i = 1; i < a.size(); i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    int cur = 0;
    for (int i = 0; i < N * 2; i++) {
        for (int j = 0; j < N * N; j++) {
            f[0][i][j] = INF;
        }
    }
    f[0][N][0] = 0;
    int maxId = 0;
    for (int i = 1; i < a.size(); i++, cur ^= 1) {
        int minJ = sum[a.size() - 1] - sum[i - 1];
        int maxJ = sum[i - 1];
        int minK = sum[a.size() - 1] - sum[i];
        int maxK = sum[i];
        int nextMaxId = 0;

        for (int i = N - minK; i <= N + maxK; i++) {
            fill(f[cur ^ 1][i], f[cur ^ 1][i] + N * N, INF);
        }

        for (int j = N - minJ; j <= N + maxJ; j++) {
            int jj = j - N;
            for (int num = 0; num <= maxId; num++) {
                if (f[cur][j][num] >= INF) continue;
                for (int k = N - minK; k <= N + maxK; k++) {
                    int kk = k - N;
                    int now = a[i] + jj - kk;
                    if (now < 0) continue;
                    if (num + abs(kk) > n * (n - 1) / 2) continue;
                    f[cur ^ 1][k][num + abs(kk)] = min(f[cur ^ 1][k][num + abs(kk)], f[cur][j][num] + now * (now - 1) / 2);
                    nextMaxId = max(nextMaxId, num + abs(kk));
                }
            }       
        }
        maxId = nextMaxId;
    }   
    int tot = sum[a.size() - 1] * (sum[a.size() - 1] - 1) / 2;
    for (int i = 0; i <= n * (n - 1) / 2; i++) {
        if (i >= 1) f[cur][N][i] = min(f[cur][N][i], f[cur][N][i - 1]);
        cout << tot - f[cur][N][i] << ' ';
    }
    cout << endl;
    return 0;
}