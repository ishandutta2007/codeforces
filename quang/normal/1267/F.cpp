#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m;
int cnt[N];
vector<int> small, big;
set<int> smallLeaves, bigLeaves;
vector<pair<int, int>> resLs;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    int szSmall, szBig;
    cin >> szSmall >> szBig;
    small.resize(szSmall);
    for (int &u : small) {
        cin >> u;
        cnt[u]++;
    }
    big.resize(szBig);
    for (int &u : big) {
        cin >> u;
        cnt[u]++;
    }
    for (int i = 1; i <= n; i++) if (!cnt[i]) smallLeaves.insert(i);
    for (int i = n + 1; i <= n + m; i++) if (!cnt[i]) bigLeaves.insert(i);

    int curSmall = 0, curBig = 0;
    while (curSmall < small.size() || curBig < big.size()) {
        if (curBig < big.size() && !smallLeaves.empty()) {
            int smallestId = *smallLeaves.begin();
            smallLeaves.erase(smallestId);
            resLs.push_back({big[curBig], smallestId});
            cnt[big[curBig]]--;
            if (cnt[big[curBig]] == 0) bigLeaves.insert(big[curBig]);
            curBig++;
            continue;
        }
        if (curSmall >= small.size()) {
            cout << "No" << endl;
            return 0;
        }
        if (bigLeaves.empty()) {
            cout << "No" << endl;
            return 0;
        }
        int smallestId = *bigLeaves.begin();
        bigLeaves.erase(smallestId);
        resLs.push_back({small[curSmall], smallestId});
        cnt[small[curSmall]]--;
        if (cnt[small[curSmall]] == 0) smallLeaves.insert(small[curSmall]);
        curSmall++;
    }
    if (smallLeaves.empty() || bigLeaves.empty()) {
        cout << "No" << endl;
        return 0;
    }
    int smallest = *smallLeaves.begin();
    while (bigLeaves.size() > 1) {
        int u = *bigLeaves.begin();
        bigLeaves.erase(u);
        resLs.push_back({u, smallest});
    }
    int biggest = *bigLeaves.begin();
    for (int u : smallLeaves) {
        resLs.push_back({biggest, u});
    }
    cout << "Yes\n";
    for (auto u : resLs) {
        cout << u.first << ' ' << u.second << '\n';
    }
    return 0;
}