#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, k;
vector<int> v;
set<int> s;
int t;

int main() {
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < n; i++) {
        if (s.count(v[i]) == 1) continue;
        if (v[i]%k == 0) s.insert(v[i]/k);
        t++;
    }
    cout << t << endl;
}