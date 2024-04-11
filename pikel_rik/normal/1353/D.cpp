#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int mod = 998244353;
const int inf = 2e9 + 5;

int a[200001];

struct comp {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second - a.first != b.second - b.first)
            return a.second - a.first < b.second - b.first;
        return a.first > b.first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> q;
        q.push({1, n});

        int i = 1;
        while (!q.empty()) {
            int r = q.top().second, l = q.top().first;
            q.pop();

            int mid = 0;

            if ((r - l + 1) % 2 != 0)
                mid = (l + r) / 2;
            else mid = (l + r - 1) / 2;

            a[mid - 1] = i++;

            if (l < mid)
                q.push({l, mid - 1});
            if (r > mid)
                q.push({mid + 1, r});
        }

        for (int j = 0; j < n; j++)
            cout << a[j] << " ";
        cout << "\n";
    }
    return 0;
}