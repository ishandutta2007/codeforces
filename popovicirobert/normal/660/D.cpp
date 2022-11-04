#include <bits/stdc++.h>
#define MAXN 2000

using namespace std;

int x[MAXN + 1], y[MAXN + 1];
map < pair <int, int>, int >  mp;

int main() {
  //  fstream cin("B.in");
  //  ofstream cout("B.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for(i = 1; i <= n; i++)
        for(j = i + 1; j <= n; j++)
           mp[{x[i] + x[j], y[i] + y[j]}]++;
    long long ans = 0;
    for(i = 1; i <= n; i++)
        for(j = i + 1; j <= n; j++) {
            ans += 1LL * mp[{x[i] + x[j], y[i] + y[j]}] * (mp[{x[i] + x[j], y[i] + y[j]}] - 1) / 2;
            mp[{x[i] + x[j], y[i] + y[j]}] = 0;
        }
    cout << ans;
  //  cin.close();
  //  cout.close();
    return 0;
}