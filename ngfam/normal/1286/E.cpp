#include<bits/stdc++.h>

using namespace std;

const int MAXN = 600060;
const long long MASK = (1 << 30) - 1;
const long long BASE = 1e15;

struct dsu{
  int par[MAXN], size[MAXN];
  dsu() {
    for(int i = 0; i < MAXN; ++i) size[i] = 1, par[i] = -1;
  }
  int find(int x) {
    return par[x] != -1 ? par[x] = find(par[x]) : x;
  }
  int join(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return -1;
    if(size[x] < size[y]) swap(x, y);
    size[x] += size[y];
    par[y] = x;
    return x;
  }
  int get_size(int x) {
    return size[find(x)];
  }
}dsu;

int n;
char s[MAXN];
int f[MAXN], g[MAXN], w[MAXN], v[MAXN];

long long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
long long cur = 0;

set < pair < int, int > > vals;

void ins(int p, int x) {
  v[p] = x;
  cur += x;
  vals.emplace(x, p); /// simply this?
}

void del(int p) { /// ?
  cur -= v[dsu.find(p)];
  dsu.size[dsu.find(p)]--; /// hmmmm
}

void minimize(int x) {
  int comp = -1;
//  cout << vals << endl;
  while(vals.size() && vals.rbegin() -> first >= x) {
    auto p = *vals.rbegin();
    vals.erase(p);
    cur -= 1LL * p.first * dsu.get_size(p.second);
  //  cout << "got sized: " << dsu.get_size(p.second) << endl;
    if(comp == -1) comp = p.second;
    else comp = dsu.join(comp, p.second);
  }
  if(comp != -1) {
    v[comp] = x;
    cur += 1LL * x * dsu.get_size(comp);
    vals.emplace(x, comp); /// most likely
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  ins(0, v[0] = MASK);

  for(int i = 1; i <= n; ++i) {
    cin >> s[i] >> w[i];
    w[i] ^= ans3 & MASK;
    s[i] = (s[i] - 'a' + ans4) % 26 + 'a';


    if(i > 1) {
      if(s[f[i - 1] + 1] == s[i]) {
        g[i - 1] = g[f[i - 1]];
      }
      else {
        g[i - 1] = f[i - 1];
      }

    //  cout << "before: " << cur << endl;
      int j = i - 1;
      while(true) {
        if(s[j + 1] == s[i]) {
          if(j == 0) break;
          j = g[j]; /// jump to next diff
        }
        else {
          if(j == 0) break;
          del(i - j);
          j = f[j];
        }
      }
  //    cout << ans << " " << s[i] << " " << vals << " " << cur << endl;
      if(s[i] == s[1]) ins(i, w[i]);
    }
    minimize(w[i]);

    ans2 += cur;
    ans1 += (ans2 / BASE);
    ans2 %= BASE;

    ans3 = (ans3 + cur) % (MASK + 1);
    ans4 = (ans4 + cur) % 26;

    //cout << ans << "\n";

    if(ans1 > 0) {
      cout << ans1;
      cout << setfill('0') << setw(15) << ans2; 
    }
    else cout << ans2;
    cout << "\n";

    if(i > 1) {
      int j = f[i - 1];
      while(true) {
        if(s[j + 1] == s[i]) {
          f[i] = j + 1;
          break;
        }
        else {
          if(j == 0) break;
          j = f[j];
        }
      }
    }
  }

  return 0;
}