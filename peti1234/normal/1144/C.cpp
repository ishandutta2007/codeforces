#include <bits/stdc++.h>

using namespace std;
int n;
set<int> a, b;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (a.find(x)==a.end()) a.insert(x);
        else if (b.find(-x)==b.end()) b.insert(-x);
        else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    cout << a.size() << "\n";
    for (auto x:a) {
        cout << x << " ";
    }
    cout << "\n";
    cout << b.size() << "\n";
    for (auto x:b) {
        cout << -x << " ";
    }
    cout << "\n";
    return 0;
}