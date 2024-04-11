#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[101010];
vector<char> c[101010];

int t[101010];
char z;
int e1[101010], e2[101010];

void haku1(int s) {
    if (t[s] == -1) return;
    t[s] = -1;
    for (int i = 0; i < v[s].size(); i++) {
        haku1(v[s][i]);
    }
}

bool ok;
int q;

void haku2(int s, int u) {
    if (t[s] == u || !ok) return;
    if (t[s] != -1) {
        ok = false;
        return;
    }
    t[s] = u;
    if (u) q++;
    for (int i = 0; i < v[s].size(); i++) {
        if (c[s][i] == z) {
            haku2(v[s][i],u);
        } else {
            haku2(v[s][i],1-u);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        char x;
        cin >> a >> b >> x;
        v[a].push_back(b);
        v[b].push_back(a);
        c[a].push_back(x);
        c[b].push_back(x);
    }
    int w1 = 0, w2 = 0;
    bool k1 = true, k2 = true;
    z = 'R';
    for (int i = 1; i <= n; i++) haku1(i);
    for (int i = 1; i <= n; i++) {
        if (t[i] != -1) continue;
        int w = 999999999;
        haku1(i);
        ok = true;
        q = 0;
        haku2(i,0);
        if (ok && q < w) {w = q; e1[i] = 0;}
        haku1(i);
        ok = true;
        q = 0;
        haku2(i,1);
        if (ok && q < w) {w = q; e1[i] = 1;}
        if (w == 999999999) {
            k1 = false;
            break;
        }
        w1 += w;
    }
    z = 'B';
    for (int i = 1; i <= n; i++) haku1(i);
    for (int i = 1; i <= n; i++) {
        if (t[i] != -1) continue;
        int w = 999999999;
        haku1(i);
        ok = true;
        q = 0;
        haku2(i,0);
        if (ok && q < w) {w = q; e2[i] = 0;}
        haku1(i);
        ok = true;
        q = 0;
        haku2(i,1);
        if (ok && q < w) {w = q; e2[i] = 1;}
        if (w == 999999999) {
            k2 = false;
            break;
        }
        w2 += w;
    }
    if (!k1 && !k2) {
        cout << "-1\n";
        return 0;
    }
    vector<int> f;
    for (int i = 1; i <= n; i++) haku1(i);
    if (k1 && (!k2 || w1 < w2)) {
        z = 'R';
        ok = true;
        for (int i = 1; i <= n; i++) {
            if (t[i] != -1) continue;
            haku2(i,e1[i]);
        }
    } else {
        z = 'B';
        ok = true;
        for (int i = 1; i <= n; i++) {
            if (t[i] != -1) continue;
            haku2(i,e2[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (t[i] == 1) f.push_back(i);
    }
    cout << f.size() << "\n";
    for (int i = 0; i < f.size(); i++) cout << f[i] << " ";
    cout << "\n";
}