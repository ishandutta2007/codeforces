#include <bits/stdc++.h>

using namespace std;
vector<int> a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--) {
        a.clear(), b.clear();
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end()), sort(b.begin(), b.end());
        for (int i=0; i<n; i++) cout << a[i] << " ";
        cout << "\n";
        for (int i=0; i<n; i++) cout << b[i] << " ";
        cout << "\n";
    }
    return 0;
}