#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define ll long long

int n;
vector<ll> v;
set<int> s;
int g[1010101];
int c[1010101];

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < 1000000; i++) s.insert(i);
    int a = 0, b = -1;
    for (int i = 2; i < 1000000; i++) {
        while ((b+1)*(b+1) <= i) {
            b++;
            if (c[g[b]] == 0) s.erase(g[b]);
            c[g[b]]++;
        }
        while (a*a*a*a < i) {
            c[g[a]]--;
            if (c[g[a]] == 0) s.insert(g[a]);
            a++;
        }
        g[i] = *s.begin();
    }
    s.clear();
    for (int i = 0; i < 1000000; i++) s.insert(i);
    for (int i = 0; i < 1000000; i++) c[i] = 0;
    a = 0; b = -1;
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] <= 2) continue;
        while ((ll)(b+1)*(b+1) <= v[i]) {
            b++;
            if (c[g[b]] == 0) s.erase(g[b]);
            c[g[b]]++;
        }
        while ((ll)a*a*a*a < v[i]) {
            c[g[a]]--;
            if (c[g[a]] == 0) s.insert(g[a]);
            a++;
        }
        x ^= (*s.begin());
    }
    if (x == 0) cout << "Rublo\n";
    else cout << "Furlo\n";
}