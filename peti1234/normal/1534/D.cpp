#include <bits/stdc++.h>

using namespace std;
int n, t[2002];
vector<int> o, e;
vector<pair<int, int> > ans;
void kerd(int a) {
    cout.flush() << "? " << a << "\n";
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    kerd(1);
    for (int i=1; i<=n; i++) {
        if (t[i]%2) {
            o.push_back(i);
        } else {
            e.push_back(i);
        }
    }
    if (e.size()>o.size()) {
        swap(o, e);
    }
    for (auto x:e) {
        if (x!=1) {
            kerd(x);
        }
        for (int i=1; i<=n; i++) {
            if (t[i]==1) {
                ans.push_back({x, i});
            }
        }
    }
    cout << "!\n";
    for (auto x:ans) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}