#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, a[c];
multiset<int> b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    for (int i=1; i<=n; i++) {
        int s=n-a[i];
        auto it=b.lower_bound(s);
        if (it==b.end()) {
            it=b.begin();
        }
        cout << (a[i]+*it)%n << " ";
        b.erase(it);
    }
    cout << "\n";
    return 0;
}