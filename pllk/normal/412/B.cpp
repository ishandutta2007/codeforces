#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> v;

int main() {
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());
    cout << v[k-1] << endl;
}