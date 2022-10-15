#include <iostream>
#include <vector>

using namespace std;

#define R 10000000

int n;
int a[101010];
vector<int> p[101010];
vector<int> z[2];

typedef long long ll;

int h;
int c[2][R+1];

void haku(int s, int e) {
    c[e][a[s]]++;
    z[e].push_back(a[s]);
    if (p[s].size() == 0) h = e;
    for (auto u : p[s]) haku(u,1-e);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        p[x].push_back(i);
    }
    haku(1,0);
    if (h == 0){
         swap(z[0],z[1]);
         for (int i = 1; i <= R; i++) {
            c[0][i] = c[1][i];
         }
    }
    int s = 0;
    for (auto u : z[1]) s ^= u;
    ll t = 0;
    ll s0 = z[0].size();
    ll s1 = z[1].size();
    if (s == 0) {
        t += s1*(s1-1)/2;
        t += s0*(s0-1)/2;
    }
    for (auto u : z[1]) {
        int s2 = s^u;
        if (s2 > R) s2 = 0;
        t += c[0][s2];
    }
    cout << t << "\n";
}