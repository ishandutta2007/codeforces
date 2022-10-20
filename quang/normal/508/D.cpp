#include <bits/stdc++.h>

#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int n;
queue <int> a[5000];
vector <int> Path;
int in[5000], out[5000];
int s = -1, f = -1, s2;

int Get(char x) {
  if (x >= 'A' && x <= 'Z') {
    return x - 'A' + 1;
  }
  if (x >= 'a' && x <= 'z') {
    return x - 'a' + 27;
  }
  return x - '0' + 53;
}

bool Check() {
  for (int i = 1; i <= 4910; i++) {
    if (in[i] == out[i]) {
      continue;
    }
    if (in[i] - out[i] == 1) {
      if (f == -1) {
        f = i;
      } else {
        return 0;
      }
    }
    if (out[i] - in[i] == 1) {
      if (s == -1) {
        s = i;
      } else {
        return 0;
      }
    }
    if (abs(in[i] - out[i]) != 1) {
      return 0;
    }
  }
  return 1;
}

void FindPath() {
  if (s == -1) {
    s = s2;
  }
  stack <int> st;
  st.push(s);
  while(!st.empty()) {
    int u = st.top(), v, sz = st.size(), d = 0;
    while (!a[u].empty()) {
      v = a[u].front();
      if (v == f && a[u].size() != 1 && !d) {
        a[u].pop();
        a[u].push(v);
        d = 1;
        continue;
      }
      st.push(v);
      a[u].pop();
      break;
    }
    if (st.size() == sz) {
      Path.push_back(u);
      st.pop();
    }
  }
}

char Turn_back(int x) {
  x /= 70;
  if (x <= 26) {
    return x + 'A' - 1;
  }
  if (x <= 52) {
    return x + 'a' - 27;
  }
  return x + '0' - 53;
}

int main() {
  //fi, fo;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    char foo[4];
    scanf("%s", foo);
    int u = Get(foo[0]);
    int v = Get(foo[1]);
    int w = Get(foo[2]);
    a[u * 70 + v].push(v * 70 + w);
    out[u * 70 + v]++;
    in[v * 70 + w]++;
    s2 = u * 70 + v;
  }
  if (!Check()) {
    puts("NO");
    return 0;
  }
  FindPath();
  if (Path.size() < n + 1) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = Path.size() - 1; i >= 0; i--) {
    putchar(Turn_back(Path[i]));
  }
  putchar(Turn_back((Path[0] % 70) * 70));
  return 0;
}