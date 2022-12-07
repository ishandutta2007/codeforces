#include <bits/stdc++.h>
#define long long long

using namespace std;

const int LG = 30;
const int maxn = 200005;
const int maxm = maxn * LG * 3;

int n;

int cntNode;
int pref[maxm];
int trie[maxm][2];

void update(int x, int val) {
    int node = 0;
    for(int i = LG-1; i >= 0; --i) {
        int b = (x >> i & 1);
        if (trie[node][b] == -1) trie[node][b] = ++cntNode;
        node = trie[node][b];
        pref[node] += val;
    }
}

int query(int x) {
    int node = 0, ans = x;
    for(int i = LG-1; i >= 0; --i) {
        int b = (x >> i & 1);
        if (b == 1 && trie[node][0] != -1) {
            ans += pref[trie[node][0]];
        }
        if (trie[node][b] == -1) break;
        node = trie[node][b];
        if (i == 0) ans += pref[node];
    }
    return ans;
}

int findSmallest(int val) {
    int low = 0, high = (int) 1e9 + maxn, ans = high;
    while(low <= high) {
        int mid = (low + high) >> 1;
        if (query(mid) >= val) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    memset(trie, -1, sizeof(trie));

    int n; cin >> n;

    int lastAns = 0;
    for(int i = 0; i < n; ++i) {
        int T; cin >> T;
        int l = findSmallest(T), r = findSmallest(T+1);
        update(0, 1);
        update(l, -1);
        update(r, -1);
        int k; cin >> k;
        while(k--) {
            int x; cin >> x;
            x = (x + lastAns) % ((int) 1e9 + 1);
            cout << (lastAns = query(x)) << "\n";
        }
    }

    return 0;
}