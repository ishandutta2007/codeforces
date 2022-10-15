#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int> > v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(make_pair(a, i));
    }
    sort(v.begin(), v.end());
    cout << v[n-1].second+1 << " " << v[n-2].first << endl;
}