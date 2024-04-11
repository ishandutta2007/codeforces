#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int q;
map<pair<int, int>, int> cnt, sym;
map<long long, set<pair<int, int> > > ls;

pair<int, int> normalize(int x, int y) {
    int z = __gcd(x, y);
    x /= z;
    y /= z;
    return make_pair(x, y);
}

int main() {
    scanf("%d", &q);
    int num = 0;
    for (int i = 1; i <= q; i++) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);
        long long c = 1ll * x * x + 1ll * y * y;
        if (t == 1) {
            num++;
            cnt[normalize(x, y)]++;
            for (auto u : ls[c]) {
                pair<int, int> foo = make_pair(x + u.first, y + u.second);
                sym[normalize(foo.first, foo.second)]++;
            }
            ls[c].insert(make_pair(x, y));
        } else if (t == 2) {
            num--;
            cnt[normalize(x, y)]--;
            ls[c].erase(make_pair(x, y));
            for (auto u : ls[c]) {
                pair<int, int> foo = make_pair(x + u.first, y + u.second);
                sym[normalize(foo.first, foo.second)]--;
            }
        } else {
            pair<int, int> foo = normalize(x, y);
            // cout << cnt[foo] << " " << sym[foo] << endl;
            printf("%d\n", num - cnt[foo] - sym[foo] * 2);
        }
    }
    return 0;
}