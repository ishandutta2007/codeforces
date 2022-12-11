#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

typedef pair<int, int> pii;

vector<pii> A;
int n, cnt[N];
int x, y, a, b;

int search(int idx, int i, int j) {
    if (i == 1 and j == 1) return 0;
    if (idx >= A.size()) return -1;

    const int key = A[idx].first, num = A[idx].second;

    vector<int> straight = {i};
    vector<int> backward = {j};

    int ans = 0;
    while (i != 1) {
        ++ans;
        i = (i + key-1) / key;
    }
    while (j != 1) {
        ++ans;
        j = (j + key-1) / key;
    }
    if (ans <= num) return ans;

    for (int k = 1; k <= num; ++k) {
        straight.push_back((straight.back() + key-1) / key);
        backward.push_back((backward.back() + key-1) / key);
    }
    reverse(backward.begin(), backward.end());

    ans = -1;
    for (int k = 0; k <= num; ++k) {
        int r = search(idx+1, straight[k], backward[k]);
        if (r != -1 and (ans == -1 or r < ans)) {
            ans = r;
        }
    }
    if (ans != -1) ans += num;

    return ans;
}
int main(void) {
    
    cin.sync_with_stdio(false);
    cin.tie(0);
    
    cin >> a >> b >> x >> y;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        ++cnt[val];
    }
    
    for (int i = N-1; i > 0; --i) {
        if (cnt[i] > 0) {
            A.push_back({i, cnt[i]});
        }
    }

    int ans1 = search(0, (a+x-1) / x, (b+y-1) / y);
    int ans2 = search(0, (b+x-1) / x, (a+y-1) / y);
    int ans = (ans1 == -1 ? ans2 : (ans2 == -1 ? ans1 : min(ans1, ans2)));
    cout << ans << endl;

    return 0;
}