#include <bits/stdc++.h>
#define MAXN 300001

using namespace std;

long long x[MAXN + 1];
long long l[MAXN + 1], r[MAXN + 1];

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> x[i];
    sort(x + 1, x + n + 1);
    for(i = 1; i <= n; i++)
        l[i] = l[i - 1] + x[i];
    for(i = n; i >= 1; i--)
        r[i] = r[i + 1] + x[i];
    long long ans = (1LL << 62);
    int p;
    for(i = 1; i <= n; i++) {
        if(ans > i * x[i] - l[i] + r[i] - (n - i + 1) * x[i]) {
            ans = i * x[i] - l[i] + r[i] - (n - i + 1) * x[i];
            p = i;
        }
    }
    cout << x[p];
    //cin.close();
    //cout.close();
    return 0;
}