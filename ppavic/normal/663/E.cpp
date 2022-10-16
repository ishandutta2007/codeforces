#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;
const int MSK = (1 << N);
const int INF = 0x3f3f3f3f;

int  a[MSK], n, m, cl[N], dp[N+1][MSK];

void dinamika(){
    for(int k = 1;k<=n;k++){
        for(int msk = 0;msk<(1 << n);msk++){
            int x = 0;
            for(int i = 0;i<n;i++){
                x += dp[k - 1][msk ^ (1 << i)];
            }
            dp[k][msk] = x;
            if(k > 1)
                dp[k][msk] += (k - 2 - n) * dp[k - 2][msk];
            dp[k][msk] /= k;
        }
    }

}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char c;scanf(" %c", &c);
            a[j] += (1 << i) * (c - '0');
        }
    }

    for(int i = 0;i<m;i++){
        dp[0][a[i]]++;
    }
    dinamika();
    int fin = INF;
    for(int i = 0;i<(1 << n);i++){
        int sol = 0;
        for(int j = 0;j<=n;j++){
            sol += dp[j][i] * min(j, n - j);
        }
        fin = min(sol, fin);
    }

    printf("%d\n", fin);
}

/**

f1(msk, i, k) = f(msk, i - 1, k - 1) - f2(msk, i, k - 1);
f1(msk, i, k) = f(msk, i - 1, k - 1) - f(msk, i, k - 1) + f1(msk, i, k - 1);

f2(msk, i, k) = f(msk, i - 1, k) - f1(msk, i, k + 1)
f2(msk, i, k) = f(msk, i - 1, k) - (f(msk, i - 1, k) - f(msk, i, k) + f1(msk, i, k))
f2(msk, i, k) = f(msk, i - 1, k) - f(msk, i - 1, k) + f(msk, i, k) - f1(msk, i, k)
f2(msk, i, k) = f(msk, i - 1, k) - f(msk, i -1 , k) + f2(msk, i, k)
0 = 0

**/