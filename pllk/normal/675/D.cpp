#include <iostream>
#include <set>
#include <map>

using namespace std;

int n, a;
set<int> s;
map<int,int> z;

int main() {
    cin >> n;
    s.insert(0);
    s.insert(1e9+1);
    cin >> a;
    s.insert(a);
    z[a] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        auto it = s.lower_bound(a);
        auto i1 = it;
        auto i2 = it;
        i1--;
        if (z[*i1] > z[*i2]) {
            cout << *i1 << " ";
        } else {
            cout << *i2 << " ";
        }
        s.insert(a);
        z[a] = i;
    }
    cout << "\n";
}