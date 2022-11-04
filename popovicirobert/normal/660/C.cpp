#include <bits/stdc++.h>
#define MAXN 300000

using namespace std;

int v[MAXN + 1];
int sp[MAXN + 1];

int main() {
  //  fstream cin("B.in");
  //  ofstream cout("B.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        sp[i] += sp[i - 1] + v[i];
    }
    int b = 1, e = 1;
    int ans = 0, p;
    while(b <= n) {
        while(e <= n && (e - b + 1) - (sp[e] - sp[b - 1]) <= k)
            e++;
        if(e - b > ans && e - b - (sp[e - 1] - sp[b - 1]) <= k) {
            ans = e - b;
            p = b;
        }
        b++;
    }
    for(i = p; i < p + ans; i++)
        v[i] = 1;
    cout << ans << endl;
    for(i = 1; i <= n; i++)
        cout << v[i] << " ";
  //  cin.close();
  //  cout.close();
    return 0;
}