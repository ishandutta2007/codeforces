#include <bits/stdc++.h>
#define MAXN 200000

using namespace std;

int a[MAXN + 1];

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    long long mn = (1LL << 60);
    int cnt = 0;
    for(i = 2; i <= n; i++)
      if(mn > a[i] - a[i - 1]) {
         mn = a[i] - a[i - 1];
         cnt = 1;
      }
      else if(mn == a[i] - a[i - 1])
         cnt++;
    cout << mn << " " << cnt;
   // cin.close();
   // cout.close();
    return 0;
}