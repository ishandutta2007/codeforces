#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        sz.push_back(x);
    }
    sort(sz.begin(), sz.end());
    cout << sz[(n-1)/2] << "\n";
    return 0;
}