#include <bits/stdc++.h>
#define ll long long
#define MAXN 2000

using namespace std;

int moves[2][2];

struct Data {
    long long val;
    int poz1;
    int poz2;
    bool operator <(const Data &other) const {
        return val < other.val;
    }

}v[MAXN * MAXN + 1];

long long a[MAXN + 1], b[MAXN + 1];

inline long long myabs(long long x) {
    if(x < 0)
        return -x;
    return x;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m, k;
    long long sa, sb, ans;
    ios::sync_with_stdio(false);
    cin >> n;
    sa = 0;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        sa += a[i];
    }
    cin >> m;
    sb = 0;
    for(i = 1; i <= m; i++) {
        cin >> b[i];
        sb += b[i];
    }
    ans = myabs(sa - sb);
    k = 0;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
          if(myabs(sa - sb + 2 * b[j] - 2 * a[i]) < ans) {
              ans = myabs(sa - sb + 2 * b[j] - 2 * a[i]);
              k = 1;
              moves[0][0] = i;
              moves[0][1] = j;
          }
    int sz = 0;
    for(i = 1; i <= n; i++)
        for(j = i + 1; j <= n; j++) {
           v[++sz].val = a[i] + a[j];
           v[sz].poz1 = i;
           v[sz].poz2 = j;
        }
    sort(v + 1, v + sz + 1);
    for(i = 1; i <= m; i++)
        for(j = i + 1; j <= m; j++) {
           long long val = sa - sb + 2 * (b[i] + b[j]);
           int rez = 0;
           for(int pas = 1 << 22; pas; pas >>= 1)
              if(rez + pas <= sz && 2 * v[rez + pas].val <= val)
                 rez += pas;
           if(rez > 0 && ans > val - 2 * v[rez].val) {
              ans = val - 2 * v[rez].val;
              k = 2;
              moves[0][0] = v[rez].poz1;
              moves[0][1] = i;
              moves[1][0] = v[rez].poz2;
              moves[1][1] = j;
           }
           rez++;
           if(rez <= sz && ans > myabs(val - 2 * v[rez].val)) {
              ans = myabs(val - 2 * v[rez].val);
              k = 2;
              moves[0][0] = v[rez].poz1;
              moves[0][1] = i;
              moves[1][0] = v[rez].poz2;
              moves[1][1] = j;
           }
        }
    cout << ans << endl << k << endl;
    for(i = 0; i < k; i++)
        cout << moves[i][0] << " " << moves[i][1] << endl;
    //cin.close();
    //cout.close();
    return 0;
}