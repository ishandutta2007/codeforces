#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long a, b, n, x;
long long A[3][3], ans[3][3], B[3][3];

inline void multiply(long long x[3][3], long long y[3][3]) {
    for(int i = 1; i <= 2; i++)
        for(int j = 1; j <= 2; j++) {
          B[i][j] = 0;
          for(int k = 1; k <= 2; k++) {
             B[i][j] += x[i][k] * y[k][j];
             B[i][j] %= MOD;
          }
        }
    for(int i = 1; i <= 2; i++)
        for(int j = 1; j <= 2; j++)
           x[i][j] = B[i][j];
}

inline void lgput() {
    for(int i = 1; i <= 2; i++)
         ans[i][i] = 1;
    while(n > 0) {
        if(n & 1)
            multiply(ans, A);
        multiply(A, A);
        n >>= 1;
    }
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    //int ;
    //ios::sync_with_stdio(false);
    cin >> a >> b >> n >> x;
    A[1][1] = 1;
    A[2][1] = 0;
    A[1][2] = b;
    A[2][2] = a;
    lgput();
    cout << (ans[1][2] + x * ans[2][2]) % MOD;
   // cin.close();
   // cout.close();
    return 0;
}