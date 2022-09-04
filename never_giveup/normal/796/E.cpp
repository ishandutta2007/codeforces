#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

short n, p, k;

short q[1002][1002][52][2];

short pr[3][1002];

inline short sum(short t, short l, short r){
    if (l > r){
        exit(1);
    }
    return pr[t][r] - pr[t][l - 1];
}

short l;
short vl;
short r;
short p1, p2;

short answer = 1;

inline void prec(){
    for (short i = 0; i <= n; i++)
    for (short j = 0; j <= p; j++)
    for (short len = k; len >= 0; len--)
    for (short t = 0; t < 2; t++)
    if (q[i][j][len][t] != 0){
        answer = max(answer, q[i][j][len][t]);
        p1 = i, p2 = p1 - len;
        vl = len + 1;
        if (i < n)
            q[i + 1][j][min(k, vl)][t] = max(q[i + 1][j][min(k, vl)][t], q[i][j][len][t]);
        if (len > 0)
            q[i][j][len - 1][t] = max(q[i][j][len - 1][t], q[i][j][len][t]);
        if (len == 0 && i < n){
            q[i + 1][j][1][t ^ 1] = max(q[i + 1][j][1][t ^ 1], q[i][j][0][t]);
            if (j < p){
                l = i + 1;
                vl = i + k;
                r = min(n, vl);
                vl = (q[i][j][0][t] + sum(0, l, r));
                q[r][j + 1][r - i][0] = max(q[r][j + 1][r - i][0], vl);
                vl = (q[i][j][0][t] + sum(1, l, r));
                q[r][j + 1][r - i][1] = max(q[r][j + 1][r - i][1], vl);
            }
        }
        if (j < p && len > 0){
            vl = p2 + k;
            l = p2 + 1, r = min(n, vl);
            vl = (q[i][j][len][t] + sum(t ^ 1, l, r) - sum(2, l, i));
            q[r][j + 1][r - p1][t ^ 1] = max(q[r][j + 1][r - p1][t ^ 1], vl);
        }
    }
}

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> p >> k;
    p = min(p, (short)(2 * (n + k - 1) / k));
    short dli;
    cin >> dli;
    for (short i = 0; i < dli; i++){
        short x;
        cin >> x;
        pr[0][x]++;
    }
    cin >> dli;
    for (short i = 0; i < dli; i++){
        short x;
        cin >> x;
        pr[1][x]++;
    }
    for (int i = 1; i <= n; i++)
        if (pr[1][i] && pr[0][i])
            pr[2][i] = 1;
    for (short i = 1; i <= n; i++)
        pr[0][i] += pr[0][i - 1], pr[1][i] += pr[1][i - 1], pr[2][i] += pr[2][i - 1];
    q[0][0][0][0] = 1;
    q[0][0][0][1] = 1;
    prec();
    cout << answer - 1;
}