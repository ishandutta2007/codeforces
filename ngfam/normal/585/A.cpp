#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 4040;

int n;
int v[N];
int d[N];
int p[N];
int id[N];

main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> v[i] >> d[i] >> p[i];
    id[i] = i;
  }

  vector < int > risan;

  int m = n, ans = 0;
  while(m > 0) {
    ++ans;
    int vx = v[1], dx = d[1], px = p[1];
    risan.push_back(id[1]);

    int add = 0;


    for(int i = 2; i <= m; ++i) {
      int sub = vx - i + 2;
      sub = max(sub, 0LL);
      p[i] -= sub + add;
      if(p[i] < 0) {
        add += d[i];
        v[i] = -1;
      }
    }
    n = 0;
    for(int i = 2; i <= m; ++i) {
      if(v[i] == -1) continue;
      ++n;
      v[n] = v[i];
      d[n] = d[i];
      p[n] = p[i];
      id[n] = id[i];
    }

    m = n;
  }

  cout << ans << endl;
  for(int x : risan) cout << x << " ";
  cout << endl;

  return 0;
}