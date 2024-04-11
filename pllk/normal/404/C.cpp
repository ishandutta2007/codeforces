#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<pair<int, int>> v;
vector<int> p[101010];
int c1[101010];
int c2[101010];
vector<pair<int, int>> e;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        v.push_back(make_pair(d, i+1));
    }
    sort(v.begin(), v.end());
    if (v[0].first != 0) {
        cout << -1 << endl;
        return 0;
    }
    p[0].push_back(v[0].second);
    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (v[i].first == 0) {
            ok = false;
            break;
        }
        int d = v[i].first;
        if (p[d-1].size() == 0) {
            ok = false;
            break;
        }
        if ((d-1 == 0 && c1[d-1] < k) || c1[d-1] < k-1) {
            e.push_back(make_pair(p[d-1][c2[d-1]], v[i].second));
            p[d].push_back(v[i].second);
            c1[d-1]++;
        } else if (c2[d-1]+1 < p[d-1].size()) {
            c2[d-1]++;
            e.push_back(make_pair(p[d-1][c2[d-1]], v[i].second));
            p[d].push_back(v[i].second);
            c1[d-1] = 1;
        } else {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << -1 << endl;
    } else {
        cout << e.size() << endl;
        for (int i = 0; i < e.size(); i++) {
            cout << e[i].first << " " << e[i].second << endl;
        }
    }
}