#include <bits/stdc++.h>

using namespace std;
int n, m, sum;
vector<int> sz;
int main()
{
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        sz.push_back(x);
    }
    sort(sz.rbegin(), sz.rend());
    for (int i=0; i<n; i++) {
        sum+=sz[i];
        if (sum>=m) {
            cout << i+1 << "\n";
            return 0;
        }
    }
    return 0;
}