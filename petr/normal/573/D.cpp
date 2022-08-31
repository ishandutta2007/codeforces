#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
int n;
int q;
scanf("%d", &n);
scanf("%d", &q);
        vector<pair<int, int> > w(n);
        vector<pair<int, int> > h(n);
        for (int i = 0; i < n; ++i) {
          scanf("%d", &(w[i].first));
          w[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
          scanf("%d", &(h[i].first));
          h[i].second = i;
        }
        sort(w.begin(), w.end());
        sort(h.begin(), h.end());
        vector<ll> c(n);
        vector<ll> c2(n);
        vector<ll> c3(n);
        for (int i = 0; i < n; ++i) {
            c[i] = w[i].first * (ll) h[i].first;
            if (i > 0) {
                c2[i] = w[i].first * (ll) h[i - 1].first + w[i - 1].first * (ll) h[i].first;
            }
            if (i > 1) {
                c3[i] = max(w[i].first * (ll) h[i - 2].first + w[i - 1].first * (ll) h[i].first + w[i - 2].first * (ll) h[i - 1].first,
                                 w[i - 2].first * (ll) h[i].first + w[i].first * (ll) h[i - 1].first + w[i - 1].first * (ll) h[i - 2].first);
            }
        }
        vector<int> p(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        for (int i = 0; i < q; ++i) {
            int a;
            int b;
            scanf("%d", &a);
            --a;
            scanf("%d", &b);
            --b;
            int t = p[a];
            p[a] = p[b];
            p[b] = t;
            ll bm2 = -1LL << 62;
            ll bm1 = -1LL << 62;
            ll bm0 = 0;
            for (int j = 0; j < n; ++j) {
                ll nb = -1LL << 62;
                if (p[w[j].second] != h[j].second) {
                    nb = bm0 + c[j];
                }
                if (j > 0) {
                    nb = max(nb, bm1 + c2[j]);
                }
                if (j > 1) {
                    nb = max(nb, bm2 + c3[j]);
                }
                bm2 = bm1;
                bm1 = bm0;
                bm0 = nb;
            }
            printf("%I64d\n", bm0);
//            out.println(bm0);
        }
        return 0;
        }