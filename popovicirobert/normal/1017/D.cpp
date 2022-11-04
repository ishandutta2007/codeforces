#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 12;
const int MAXQ = (int) 5e5;

int cst[MAXN], sum[1 << MAXN], fr[1 << MAXN];

int dp[1 << MAXN][101];
string str;

int n;

inline int get(int a, int b) {
    return (1 << n) - 1 - (a ^ b);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, m, q, x;
    //ios::sync_with_stdio(false);
    //cin >> n >> m >> q;
    scanf("%d%d%d" ,&n,&m,&q);
    for(i = 0; i < n; i++) {
        //cin >> cst[i];
        scanf("%d" ,&cst[i]);
    }
    fgetc(stdin);
    reverse(cst, cst + n);
    for(int conf = 0; conf < (1 << n); conf++) {
        int cur = 0;
        for(i = 0; i < n; i++) {
            if(conf & (1 << i))
                cur += cst[i];
        }
        sum[conf] = cur;
    }
    while(m > 0) {
        m--;
        //cin >> str;
        int conf = 0;
        for(i = 0; i < n; i++) {
            char it = fgetc(stdin);
            conf = conf * 2 + it - '0';
        }
        fgetc(stdin);
        fr[conf]++;
    }
    for(int a = 0; a < (1 << n); a++) {
        for(int b = 0; b < (1 << n); b++) {
            x = get(a, b);
            if(sum[x] <= 100)
                dp[a][sum[x]] += fr[b];
        }
        for(i = 1; i <= 100; i++) {
            dp[a][i] += dp[a][i - 1];
        }
    }
    while(q > 0) {
        q--;
        int conf = 0;
        for(i = 0; i < n; i++) {
            char it = fgetc(stdin);
            conf = conf * 2 + it - '0';
        }
        scanf("%d" ,&x);
        fgetc(stdin);
        printf("%d\n" ,dp[conf][x]);
    }
    //cin.close();
    //cout.close();
    return 0;
}