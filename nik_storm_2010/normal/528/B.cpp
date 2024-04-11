#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 3e5;

vector <pii> gran;
int tree[N];

bool cmp(const pii &a, const pii &b) {
    return (a.second < b.second);
}

void modify(int x, int value) {
    for (int i = x; i < N; i = (i | (i + 1))) {
        tree[i] = max(tree[i], value);
    }
}

int get(int x) {
    int res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        res = max(res, tree[i]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, w;
        cin >> x >> w;
        gran.push_back(make_pair(x - w, x + w));
    }
    sort(gran.begin(), gran.end(), cmp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = -1, r = i;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (gran[mid].second <= gran[i].first) {
                l = mid;
            } else {
                r = mid;
            }
        }
        int cur = 1 + get(l);
        modify(i, cur);
        ans = max(ans, cur);
    }
    cout << ans << "\n";
    return 0;
}