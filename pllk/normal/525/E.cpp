#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define ll unsigned long long

int n, k;
ll s;
vector<ll> v1, v2;
map<ll,map<int,int>> m1, m2;
ll c[20];
ll z;
vector<ll> v3;
map<ll,int> m3;

void haku1(int k, ll u, int q) {
    if (u > s) return;
    if (k == v1.size()) {
        if (m3[u] == 0) v3.push_back(u);
        m1[u][q]++;
        m3[u] = 1;
        return;
    }
    haku1(k+1, u, q);
    haku1(k+1, u+v1[k], q);
    if (v1[k] <= 18) haku1(k+1, u+c[v1[k]], q+1);
}

void haku2(int k, ll u, int q) {
    if (u > s) return;
    if (k == v2.size()) {
        m2[u][q]++;
        return;
    }
    haku2(k+1, u, q);
    haku2(k+1, u+v2[k], q);
    if (v2[k] <= 18) haku2(k+1, u+c[v2[k]], q+1);
}

int main() {
    c[0] = 1;
    for (int i = 1; i <= 18; i++) c[i] = c[i-1]*i;
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i%2 == 1) v1.push_back(x);
        else v2.push_back(x);
    }
    haku1(0, 0, 0);
    haku2(0, 0, 0);
    for (int i = 0; i < v3.size(); i++) {
        for (int a = 0; a <= k; a++) {
            for (int b = 0; a+b <= k; b++) {
                z += (ll)m1[v3[i]][a]*m2[s-v3[i]][b];
            }
        }
    }
    cout << z << "\n";
}