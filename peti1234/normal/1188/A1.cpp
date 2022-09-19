#include <bits/stdc++.h>
 
using namespace std;
int n;
vector<int> sz[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
        sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (sz[i].size()==2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}