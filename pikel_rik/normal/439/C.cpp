#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, p;
    cin >> n >> k >> p;

    if (k == 0 and p == 0) {
        cout << "NO\n";
        return 0;
    }

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int c1 = p, c2 = k - p;

    vvi ans;
    vector<bool> visited(n);

    for (int i = 0; i < n; i++) {
        if (c1 > 0 and a[i] % 2 == 0) {
            ans.push_back({a[i]});
            c1 -= 1;
            visited[i] = true;
        }
        else if (c2 > 0 and a[i] % 2 != 0) {
            ans.push_back({a[i]});
            c2 -= 1;
            visited[i] = true;
        }
    }

    vi temp;
    for (int i = 0; i < n; i++) {
        if (!visited[i] and a[i] % 2 != 0)
            temp.push_back(i);
    }

    if (temp.size() % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 1; i < temp.size(); i += 2) {
        if (c1 == 0) break;

        ans.push_back({a[temp[i]], a[temp[i-1]]});
        visited[temp[i]] = visited[temp[i-1]] = true;
        c1 -= 1;
    }
    
    if (c1 > 0 or c2 > 0) {
        cout << "NO\n";
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] and a[i] % 2 == 0) {
            ans.back().push_back(a[i]);
            visited[i] = true;
        }
    }

    for (int i = 1; i < temp.size(); i += 2) {
        if (!visited[temp[i]] and !visited[temp[i - 1]]) {
            ans[0].push_back(a[temp[i]]);
            ans[0].push_back(a[temp[i - 1]]);
            visited[temp[i]] = visited[temp[i - 1]] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    for (auto & an : ans) {
        if (an.empty()) continue;

        cout << an.size() << " ";
        for (int j : an) {
            cout << j << " " ;
        }
        cout << "\n";
    }

    return 0;
}