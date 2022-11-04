#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int v[MAXN + 1], l[MAXN + 1], r[MAXN + 1];

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    l[0] = n + 1;
    for(i = 1; i <= n; i++)
        if(v[i] != 0)
            l[i] = l[i - 1] + 1;
    r[n + 1] = n + 1;
    for(i = n; i >= 1; i--)
        if(v[i] != 0)
            r[i] = r[i + 1] + 1;
    for(i = 1; i <= n; i++)
        cout << min(l[i], r[i]) << " ";
   // cin.close();
   // cout.close();
    return 0;
}