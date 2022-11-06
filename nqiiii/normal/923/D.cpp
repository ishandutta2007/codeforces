#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;
const int kN = 100010;
char s[kN], t[kN];
int l_s, l_t, q;
int s_sum_b[kN], s_suf_a[kN];
int t_sum_b[kN], t_suf_a[kN];
int main() {
  scanf("%s%s", s + 1, t + 1);
  l_s = strlen(s + 1);
  l_t = strlen(t + 1);
  for (int i = 1; i <= l_s; ++i) {
    if (s[i] == 'C') s[i] = 'B';
    if (s[i] == 'B') s_sum_b[i] = s_sum_b[i - 1] + 1;
    else {
      s_sum_b[i] = s_sum_b[i - 1];
      s_suf_a[i] = s_suf_a[i - 1] + 1;
    }
  }
  for (int i = 1; i <= l_t; ++i) {
    if (t[i] == 'C') t[i] = 'B';
    if (t[i] == 'B') t_sum_b[i] = t_sum_b[i - 1] + 1;
    else {
      t_sum_b[i] = t_sum_b[i - 1];
      t_suf_a[i] = t_suf_a[i - 1] + 1;
    }
  }
  scanf("%d", &q);
  while (q--) {
    int s_l, s_r, t_l, t_r;
    scanf("%d%d%d%d", &s_l, &s_r, &t_l, &t_r);
    int v1 = min(s_r - s_l + 1, s_suf_a[s_r]);
    int v2 = min(t_r - t_l + 1, t_suf_a[t_r]);
    if (v2 > v1) printf("0");
    else {
      v1 -= v2;
      int p1 = s_sum_b[s_r] - s_sum_b[s_l - 1];
      int p2 = t_sum_b[t_r] - t_sum_b[t_l - 1];
      if (p1) {
        v1 %= 3; v1 = min(v1, 1);
        p1 += v1 * 2;
        if (p1 <= p2 && (p1 + p2) % 2 == 0) printf("1");
        else printf("0");
      } else if (!v1) printf("%d", !p2);
      else {
        if (p2) {
          --v1; p1 += 2;
        }
        v1 %= 3; if (!p2) p1 += v1 * 2;
        if (p1 <= p2 && (p1 + p2) % 2 == 0) printf("1");
        else printf("0");
      }
    }
  }
}