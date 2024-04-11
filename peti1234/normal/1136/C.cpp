#include <bits/stdc++.h>

using namespace std;
vector<int> a[1001];
vector<int> b[1001];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int x;
            cin >> x;
            a[i+j].push_back(x);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int x;
            cin >> x;
            b[i+j].push_back(x);
        }
    }
    for (int i=1; i<=1000; i++) {
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
    }
    for (int i=1; i<=1000; i++) {
        for (int j=0; j<a[i].size(); j++) {
            if (a[i][j]!=b[i][j]) {
                cout << "NO" << "\n";
                return 0;
            }
        }
    }
    cout << "YES" << "\n";
    return 0;
}