#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int K = 20;

int n, m, k;
string t, s;
pair<int, int> a[N];
int maxId[1 << K], minId[1 << K];

int getMask(const string &u) {
    int res = 0;
    for (int i = 0; i < k; i++) {
        res |= (u[i] == '1') << i;
    }
    return res;
}

string getBit(int u) {
    string res = "";
    for (int i = 0; i < k; i++) {
        res += (char)((u >> i & 1) + '0');
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    cin >> s;
    cin >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first--;
        a[i].second--;
    }

    for (int i = 0; i < (1 << k); i++) {
        maxId[i] = 0;
        minId[i] = n + 1;
    }

    int curMask;
    vector<int> perm(k, 0);
    iota(perm.begin(), perm.end(), 0);
    curMask = getMask(s);
    for (int i = n; i; i--) {
        int x = perm[a[i].first];
        int y = perm[a[i].second];
        swap(perm[a[i].first], perm[a[i].second]);
        int bitX = curMask >> x & 1;
        int bitY = curMask >> y & 1;
        if (bitX != bitY) {
            curMask ^= (1 << x) | (1 << y);
        }
        // cout << i << ' ' << getBit(curMask) << endl;
        minId[curMask] = min(minId[curMask], i);
    }

    curMask = getMask(t);
    maxId[curMask] = n + 1;
    iota(perm.begin(), perm.end(), 0);
    for (int i = n; i; i--) {
        int x = perm[a[i].first];
        int y = perm[a[i].second];
        swap(perm[a[i].first], perm[a[i].second]);
        int bitX = curMask >> x & 1;
        int bitY = curMask >> y & 1;
        if (bitX != bitY) {
            curMask ^= (1 << x) | (1 << y);
        }
        maxId[curMask] = max(maxId[curMask], i);
    }


    for (int i = 0; i < k; i++) {
        for (int mask = 0; mask < (1 << k); mask++) {
            if (mask >> i & 1) {
                int subMask = mask ^ (1 << i);
                minId[subMask] = min(minId[subMask], minId[mask]);
                maxId[subMask] = max(maxId[subMask], maxId[mask]);
            }
        }
    }

    int res = 0;
    pair<int, int> resId(1, n);

    for (int mask = 0; mask < (1 << k); mask++) {
        int numBit = __builtin_popcount(mask);
        // cout << "mask " << mask << ' ' << minId[mask] << ' ' << maxId[mask] << endl;
        if (minId[mask] + m <= maxId[mask]) {
            if (res < numBit) {
                res = numBit;
                resId = {minId[mask], maxId[mask] - 1};
                // cout << "update " << res <<  ' ' << getBit(mask) << endl;
                // cout << resId.first << ' ' << resId.second << endl;
            }
        }   
    }

    res = k + 2 * res - __builtin_popcount(getMask(s)) - __builtin_popcount(getMask(t));

    cout << res << endl;
    cout << resId.first << ' ' << resId.second << endl;
    return 0;
}