#include <iostream>
#include <set>
#include <map>
#include <vector>

#define ll long long int

using namespace std;

int n;
set<ll> s;
map<int, ll> p;
map<int, ll> m;
ll t;
ll u, v;
int vo, va, vb;
vector<ll> q;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        q.push_back(a);
        if (a >= 0) t += a;
        if (s.count(a)) {
            if (a >= 0) {
                u = t-m[a]+a;
            } else {
                u = t-m[a]+2*a;
            }
            if (u > v || !vo) {
                vo = 1;
                va = p[a];
                vb = i;
                v = u;
            }
            if (t < m[a]) {
                m[a] = t;
                p[a] = i;
            }
        } else {
            s.insert(a);
            m[a] = t;
            p[a] = i;
        }
    }
    vector<int> r;
    for (int i = 0; i < va; i++) r.push_back(i+1);
    for (int i = va+1; i <= vb-1; i++) {
        if (q[i] < 0) r.push_back(i+1);
    }
    for (int i = vb+1; i < n; i++) r.push_back(i+1);
    cout << v << " " << r.size() << endl;
    for (int i = 0; i < r.size(); i++) cout << r[i] << " ";
    cout << endl;
}