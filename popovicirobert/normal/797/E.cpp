#include <bits/stdc++.h>
#define MAXN 100000
#define LOG 16

using namespace std;

struct Query {
    int p;
    int k;
    int pos;
    bool operator <(const Query &other) const {
        return k < other.k;
    }
}qry[MAXN + 1];

int v[MAXN + 1];
int sol[MAXN + 1];
int dp[MAXN + 1];

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i, n, p, lg, q, cnt, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    cin >> q;
    for(i = 1; i <= q; i++) {
        cin >> qry[i].p >> qry[i].k;
        qry[i].pos = i;
    }
    sort(qry + 1, qry + q + 1);
    int len = sqrt(n);
    for(i = 1; i <= q; i++)
        if(qry[i].k > len) {
            cnt = 0;
            p = qry[i].p;
            while(p <= n) {
                p += qry[i].k + v[p];
                cnt++;
            }
            sol[qry[i].pos] = cnt;
        }
    p = 1;
    while(p <= q && qry[p].k <= len) {
       for(i = n; i >= 1; i--)
           if(i + qry[p].k + v[i] > n)
              dp[i] = 1;
           else
              dp[i] = dp[i + qry[p].k + v[i]] + 1;
       int aux = qry[p].k;
       while(p <= q && qry[p].k == aux) {
           sol[qry[p].pos] = dp[qry[p].p];
           p++;
       }
    }
    for(i = 1; i <= q; i++)
        cout << sol[i] << endl;
   // cin.close();
   // cout.close();
    return 0;
}