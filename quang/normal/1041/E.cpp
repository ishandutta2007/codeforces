#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int cnt[N];
vector<pair<int, int> > res;
vector<int> a;

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u < v) {
            swap(u, v);
        }
        if (u != n) {
            puts("NO");
            return 0;
        }
        cnt[v]++;
    }
    for (int i = 1; i < n; i++) {
        if (cnt[i] == 0) {
            a.push_back(i);
        } else {
            int last = i;
            if (a.size() + 1 < cnt[i]) {
                puts("NO");
                return 0;
            }
            for (int j = 1; j < cnt[i]; j++) {
                res.push_back(make_pair(last, a.back()));
                last = a.back();
                a.pop_back();
            }
            res.emplace_back(last, n);
        }
    }
    if (res.size() != n - 1) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (auto u : res) {
        printf("%d %d\n", u.first, u.second);
    }
    return 0;
}