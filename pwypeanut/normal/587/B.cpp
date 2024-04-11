#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int N, K, arr[1000005], olda[1000005];
bool exist[1000005];
multiset<int> S;
long long L;

int main() {
    cin >> N >> L >> K;
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < N; i++) olda[i] = arr[i];
    for (int i = 0; i < L % N; i++) S.insert(olda[i]);
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        if (S.find(arr[i]) == S.end()) continue;
        else {
            S.erase(S.find(arr[i]));
            exist[i] = 1;
        }
    }
    int dp[K + 1][N];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++) dp[1][i] = 1;
    for (int i = 2; i <= K; i++) {
        long long sum = 0;
        int curpos = 0;
        for (int j = 0; j < N; j++) {
            while (arr[curpos] <= arr[j] && curpos < N) {
                sum += dp[i - 1][curpos];
                sum %= MOD;
                curpos++;
            }
            dp[i][j] = sum;
            //printf("%d %d %d\n", i, j, sum);
        }
    }
    long long ans = 0;
    long long no = L / N;
   // printf("no: %lld\n", no);
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < N; j++) {
            long long seq_count = (no - i + 1) + (exist[j]);
            seq_count = max(0ll, seq_count);
            //printf("seq_count(%d,%d) = %lld\n",i, j, seq_count);
            ans += (seq_count % MOD) * dp[i][j];
            ans %= MOD;
        }
    }
    //printf("exist: ");
    //for (int i = 0; i < N; i++) printf("%d ", exist[i]);
    //printf("\n");
    cout << ans << endl;
}