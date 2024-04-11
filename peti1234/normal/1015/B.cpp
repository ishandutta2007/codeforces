#include <bits/stdc++.h>

using namespace std;
int n;
string a, b;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (a[j]==b[i]) {
                for (int k=j; k>i; k--) {
                    ans.push_back(k);
                    swap(a[k], a[k-1]);
                }
                break;
            }
        }
    }
    if (a!=b) {
        cout << -1 << "\n";
    } else {
        cout << ans.size() << "\n";
        for (auto x:ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}