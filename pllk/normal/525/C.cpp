#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int n;
vector<int> v;
ll kk;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    bool u = false;
    int q;
    while (v.size() >= 2) {
        int p1 = v[v.size()-1];
        int p2 = v[v.size()-2];
        if (p1 == p2 || p1-1 == p2) {
            if (u) {
                kk += (ll)q*p2;
                u = false;
            } else {
                q = p2;
                u = true;
            }
            v.pop_back();
            v.pop_back();
        } else {
            v.pop_back();
        }
    }
    cout << kk << "\n";
}