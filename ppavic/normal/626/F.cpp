#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 205;
const int K = 1005;
const ll MOD = 1e9 + 7;

int a[N], n, k;
int raz[N], dp[N][N / 2][K];

int f(int i,int x,int sm){
    if(sm > k || x < 0 || x > n / 2) return 0;
    if(i == n) return (x == 0);
    if(dp[i][x][sm] != -1) return dp[i][x][sm];
    dp[i][x][sm] = (ll)f(i + 1, x - 1, sm + raz[i] * x) * x % MOD;
    dp[i][x][sm] = (dp[i][x][sm] + (ll)f(i + 1, x, sm + raz[i] * x) * (x + 1) % MOD) % MOD;
    dp[i][x][sm] = (dp[i][x][sm] + f(i + 1, x + 1, sm + raz[i] * x)) % MOD;
    return dp[i][x][sm];
}

int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &n, &k);
    for(int i = 0;i<n;i++){
        scanf("%d", a + i);
    }
    sort(a, a + n);
    for(int i = 0;i<n;i++){
        raz[i] = a[i] - (i ? a[i - 1] : 0);
    }
    printf("%d\n", f(0,0,0));
}