#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int n;
pair<ll,ll> x;
vector<pair<ll,ll>> v;
multiset<ll> u;
int p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    v.resize(n-1);
    cin >> x.first >> x.second;
    for (int i = 0; i < n-1; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(),v.end());
    while (v.size() > 0 && v.back().first > x.first) {
        u.insert(v.back().second-v.back().first);
        v.pop_back();
    }
    p = (int)u.size()+1;
    while (true) {
        auto e = *u.begin()+1;
        if (x.first >= e) {
            x.first -= e;
            u.erase(u.begin());
            while (v.size() > 0 && v.back().first > x.first) {
                u.insert(v.back().second-v.back().first);
                v.pop_back();
            }
            p = min(p,(int)u.size()+1);
        } else {
            break;
        }
    }
    cout << p << "\n";
}