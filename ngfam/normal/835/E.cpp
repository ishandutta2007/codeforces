#include<bits/stdc++.h>

using namespace std;

int n, x, y;

#ifdef ngfam
#define LOCAL
#endif

struct TGrader{
  int p1, p2;

  TGrader() {
    #ifdef LOCAL
      cin >> n >> x >> y >> p1 >> p2;
    #else
      cin >> n >> x >> y;
    #endif
  }

  int ask(vector<int> pos) {
    if(pos.size() == 0) return 0;
    for(int i = 1; i < pos.size(); ++i) if(pos[i] <= pos[i - 1]) {
      cout << "Invalid Queries" << endl;
      exit(0);
    }
    #ifdef LOCAL
      int ans = 0;
      for(int p : pos) {
        if(p == p1 || p == p2) ans ^= y;
        else ans ^= x;
      }
      return ans;
    #else
      cout << "? " << pos.size() << " ";
      for(int p : pos) cout << p << " ";
      cout << endl;
      int ans; cin >> ans;
      return ans;
    #endif
  }

  void guess(int x, int y) {

    #ifdef LOCAL
      if(x == p1 && y == p2) {
        cout << "Correct Answer!!!" << endl;
        exit(0);
      }
      else {
        cout << "wrong: " << x << " " << y << endl;
        exit(0);
      }
    #else
      cout << "! " << x << " " << y << endl;
      exit(0);
    #endif
  }
}Grader;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  vector<int> f(10);

  int need = -1;

  for(int bit = 0; bit < 10; ++bit) {
    vector<int> cur;
    for(int i = 0; i < n; ++i) if(i & (1 << bit)) cur.push_back(i + 1);
    f[bit] = Grader.ask(cur);
    if(f[bit] == y || (f[bit] == (x ^ y))) {
      need = bit;
    }
  }

  vector<int> risan(2);
  risan[0] = 1 << need;


  vector<int> g(10);
  for(int bit = 0; bit < 10; ++bit) {
    if(bit == need) continue;
    vector<int> cur;
    for(int i = 0; i < n; ++i) if((i & (1 << bit)) && (i & (1 << need))){
      cur.push_back(i + 1);
    }
    g[bit] = Grader.ask(cur);
    if(g[bit] == y || g[bit] == (x ^ y)) risan[0] |= 1 << bit;
  }

  for(int i = 0; i < 10; ++i) {
    if(risan[0] & (1 << i)) f[i] ^= y;
    if(f[i] == y || f[i] == (x ^ y)) risan[1] ^= (1 << i);
  }

  if(risan[0] > risan[1]) swap(risan[0], risan[1]);

  Grader.guess(risan[0] + 1, risan[1] + 1);

  return 0;
}