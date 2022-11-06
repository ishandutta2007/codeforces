#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
using std::vector;
using std::set;
const int kN = 200010;
char s[kN];
int l,tot;
vector<int> ans[kN];
set <int> ch[2];
int main() {
  scanf("%s", s + 1);
  l = strlen(s + 1);
  for (int i = 1; i <= l; ++i)
    if (s[i] == '0') ++tot; else --tot;
  if (tot <= 0)
    printf("-1");
  else {
    for (int i = 1; i <= tot; ++i) ch[1].insert(i);
    for (int i = 1; i <= l; ++i) {
      int d = (s[i] - '0') ^ 1;
      if (ch[d].empty()) {
        printf("-1"); return 0;
      }
      int x = *ch[d].begin();
      ans[x].push_back(i);
      ch[d].erase(x); ch[d^1].insert(x);
    }
    for (int i = 1; i <= tot; ++i) {
      if (ans[i].empty()) {
        printf("-1"); return 0;
      }
      if (s[ans[i][0]] == '1' || s[ans[i][ans[i].size() - 1]] == '1') {
        printf("-1"); return 0;
      }
    }
    printf("%d\n",tot);
    for (int i = 1; i <= tot; ++i) {
      printf("%d ", ans[i].size());
      for (int j = 0; j < ans[i].size(); ++j)
        printf("%d ", ans[i][j]);
      printf("\n");
    }
  }
}