#include <bits/stdc++.h>

using namespace std;
int n, el=1, db;
vector<int> sz;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (__gcd(x, el)>1) {
            db++;
            sz.push_back(1);
        }
        sz.push_back(x);
        el=x;
    }
    cout << db << "\n";
    for (auto x:sz) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}