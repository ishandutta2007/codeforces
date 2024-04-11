#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a;
vector<pair<int, int> > v;
int r[303030];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(make_pair(a, i));
    }
    sort(v.begin(), v.end());
    int q = 0;
    for (int i = 0; i < n; i++) {
        r[v[i].second] = max(q+1, v[i].first);
        q = r[v[i].second];
    }
    for (int i = 0; i < n; i++) cout << r[i] << " ";
    cout << endl;
}