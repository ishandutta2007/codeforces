#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int n, id[c], x[c], y[c], ki[c];
vector<int> res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> id[i] >> x[i];
        if (id[i]==2) {
            cin >> y[i];
        }
    }
    for (int i=0; i<c; i++) {
        ki[i]=i;
    }
    for (int i=n; i>=1; i--) {
        if (id[i]==1) {
            res.push_back(ki[x[i]]);
        } else {
            ki[x[i]]=ki[y[i]];
        }
    }
    reverse(res.begin(), res.end());
    for (auto x:res) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}