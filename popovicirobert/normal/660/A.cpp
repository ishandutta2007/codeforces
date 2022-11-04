#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

int v[MAXN + 1];

inline int gcd(int a, int b) {
    int r;
    while(b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
  //  fstream cin("B.in");
  //  ofstream cout("B.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    int ans = 0;
    for(i = 1; i < n; i++)
        if(gcd(v[i], v[i + 1]) > 1)
            ans++;
    cout << ans << endl;
    for(i = 1; i < n; i++) {
        cout << v[i] << " ";
        if(gcd(v[i], v[i + 1]) > 1)
            cout << 1 << " ";
    }
    cout << v[n];
  //  cin.close();
  //  cout.close();
    return 0;
}