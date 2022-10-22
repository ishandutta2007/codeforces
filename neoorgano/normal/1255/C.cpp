#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
array<int, 3> arr[MAXN];
int cnt[MAXN];

pair<int, array<int, 3>> inter(array<int, 3> a, array<int, 3> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cur = 0;
    int j = 0;
    array<int, 3> res = {-1, -1, -1};
    for (int i = 0; i < 3; ++i) {
        while(j < 3 && b[j] < a[i]) {
            j++;
        }
        if (b[j] == a[i]) {
            res[cur] = b[j];
            cur++;
        }
    }
    return {cur, res};
}

int del(pair<int, int> a, array<int, 3> b) {
    if (b[0] != a.first && b[0] != a.second) {
        return b[0];
    }
    if (b[1] != a.first && b[1] != a.second) {
        return b[1];
    }
    if (b[2] != a.first && b[2] != a.second) {
        return b[2];
    }
}

main() {
    int n;
    cin >> n;
    map<pair<int, int>, vector<int>> mp;
    for (int i = 0; i < n - 2; ++i) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        cnt[arr[i][0]]++;
        cnt[arr[i][1]]++;
        cnt[arr[i][2]]++;
        mp[{arr[i][0], arr[i][1]}].push_back(i);
        mp[{arr[i][1], arr[i][0]}].push_back(i);
        mp[{arr[i][0], arr[i][2]}].push_back(i);
        mp[{arr[i][2], arr[i][0]}].push_back(i);
        mp[{arr[i][1], arr[i][2]}].push_back(i);
        mp[{arr[i][2], arr[i][1]}].push_back(i);
    }
    int s = -1;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 1) {
            s = i;
            break;
        }
    }
    vector<int> ans;
    ans.push_back(s);
    for (int i = 0; i < n - 2; ++i) {
        if (inter({s, -1, -1}, arr[i]).first == 1) {
            int a = arr[i][0];
            int b = arr[i][1];
            int c = arr[i][2];
            if (cnt[a] == 2) {
                ans.push_back(a);
            } else if (cnt[b] == 2) {
                ans.push_back(b);
            } else {
                ans.push_back(c);
            }
        }
    }
    int l = -1;
    for (int i = 0; i < n - 2; ++i) {
        pair<int, int> el = {ans[i], ans[i + 1]};
        for (auto j : mp[el]) {
            if (j == l) {
                continue;
            }
            // cout << j << " " << l << endl;;
            ans.push_back(del(el, arr[j]));
            l = j;
            break;
        }
        // cout << endl;
        // cout << l << endl;
    }
    for (auto elem : ans) {
        cout << elem << " ";
    }
    return 0;
}