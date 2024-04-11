#include <iostream>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int n;
set<ll> e;
map<ll,int> up,down;
ll result[202020];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll a, b;
        cin >> a >> b;
        e.insert(a);
        e.insert(b);
        up[a]++;
        down[b]++;
    }
    int c = 0;
    ll p = 0;
    for (auto x : e) {
        if (x-p-1 > 0) {
            result[c] += x-p-1;
        }
        c += up[x];
        result[c]++;
        c -= down[x];
        p = x;
    }
    for (int i = 1; i <= n; i++) cout << result[i] << " ";
    cout << "\n";
}