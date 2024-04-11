#include <iostream>
#include <vector>
#include <string>

using namespace std;


const int Max = 50000;
int n, k;
int next[2 * Max + 2];
int first[Max];
unsigned int  dp[Max][501];
int top[Max];
unsigned int  nowA[501];
int rA[2 * Max + 2];
int rB[2 * Max + 2];
int r = 0;
//
unsigned int  res(int v, int k) {
    if (k == 0) return 1;
    if (dp[v][k] != -1) return dp[v][k];
    unsigned int  sum = 0;
    int v1 = first[v];
    while (v1 != -1) {
        if (top[rB[v1]] > top[v])
            sum += res(rB[v1], k - 1);
        v1 = next[v1];
    }
    dp[v][k] = sum;
    return dp[v][k];
}
//
void dfs(int v, int value) {
    top[v] = value;
    int v1 = first[v];
    while (v1 !=-1) {
        if (top[rB[v1]] == 0) {
            dfs(rB[v1], value + 1);
        }
        v1 = next[v1];
    }   
}
//
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        first[i] = -1;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        rA[r] = x - 1;
        rB[r] = y - 1;
        next[r] = first[x - 1];
        first[x - 1] = r;
        r++;
        rA[r] = y - 1;
        rB[r] = x - 1;
        next[r] = first[y - 1];
        first[y - 1] = r;
        r++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) 
            dp[i][j] = -1;
    }
    dfs(0, 1);
    //
    unsigned int ans = 0;
    for (int v = 0; v < n; v++) {
        ans += res(v, k);
        for (int i = 0; i <= k; i++)
            nowA[i] = 0;
        int v1 = first[v];
        while (v1 != -1) {
            if (top[rB[v1]] > top[v]) {
                for (int k1 = 0; k1 < k; k1++)
                    nowA[k1 + 1] += res(rB[v1], k1);
            }
            v1 = next[v1];
        }
        unsigned int add1 = 0;
        for (int k1 = 1; k1 < k; k1++) {
            int v1 = first[v];
            while (v1 != -1) {
                if (top[rB[v1]] > top[v])
                    add1 += (nowA[k - k1] - res(rB[v1],  k - k1 - 1))*(res(rB[v1], k1 - 1));
                v1 = next[v1];
            }   
            
        }
        ans += add1/2;
    }
    //
    cout << ans << endl;
}