#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int n, q;
int a[3][MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> q;

  int x = 0, y = 0;
  while(q--) {
    int u, v; cin >> u >> v;

    int sign = 1;
    if(a[u][v]) sign = -1;

    if(a[3 - u][v]) x += sign;
    if(a[3 - u][v - 1]) y += sign;
    if(a[3 - u][v + 1]) y += sign;
    a[u][v] ^= 1;

    if(!x && !y && !a[2][n]) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}