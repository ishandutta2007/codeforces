#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

int n;
int p[1222333];
int e[1222333];
vector<int> v[1222333];
int s;

int c[1222333];
int d[1222333];
vector<int> z;

int w[1222333];
int r;

void haku1(int k, int u) {
    d[k] = u;
    c[k] = p[k];
    for (int i = 0; i < v[k].size(); i++) {
        haku1(v[k][i],u+1);
        c[k] += c[v[k][i]];
        w[k] += w[v[k][i]];
    }
    if (c[k] == s) w[k]++;
}

void haku2(int k) {
    if (k != r && c[k] == s && w[k] == 1) z.push_back(k);
    for (int i = 0; i < v[k].size(); i++) {
        haku2(v[k][i]);
    }
}

void haku4(int k, int q) {
    if (c[k] == s && q) {
        cout << k << "\n";
        exit(0);
    }
    for (int i = 0; i < v[k].size(); i++) {
        haku4(v[k][i],1);
    }
}

void haku3(int k) {
    for (int i = 0; i < v[k].size(); i++) {
        haku3(v[k][i]);
    }
    int ok = (c[k] != s && w[k] > 0) || w[k] > 1;
    if (k != r && ok && c[k] == 2*s) {
        cout << k << " ";
        haku4(k,0);
    }
}

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        e[i] = a;
        p[i] = b;
        if (a != 0) {
            v[a].push_back(i);
        } else {
            r = i;
        }
        s += b;
    }
    if (s%3 != 0) {
        cout << "-1\n";
        return 0;
    }
    s /= 3;
    haku1(r,0);
    haku2(r);
    if (z.size() >= 2) {
        int a = z[0];
        int b = z[z.size()-1];
        if (d[a] > d[b]) swap(a,b);
        int f = b;
        while (d[f] != d[a]) f = e[f];
        if (a != f) {
            cout << a << " " << b << "\n";
            return 0;
        }
    }
    haku3(r);
    cout << "-1\n";
}