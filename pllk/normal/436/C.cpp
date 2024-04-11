#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, w;

string s[1111];
vector<pair<int,pair<int,int>>> v;
int c, r;

int aa[1111];
int ab[1111];

bool sama(int a, int b) {
    while (aa[a] != a) a = aa[a];
    while (aa[b] != b) b = aa[b];
    return a == b;
}

int liita(int a, int b) {
    while (aa[a] != a) a = aa[a];
    while (aa[b] != b) b = aa[b];
    if (ab[a] > ab[b]) {
        ab[a] += ab[b];
        aa[b] = a;
    } else {
        ab[b] += ab[a];
        aa[a] = b;
    }
}

int ok[1111];
vector<pair<int,int>> va;
vector<int> ww[1111];

void haku(int s, int e) {
    va.push_back(make_pair(s, e));
    for (int i = 0; i < ww[s].size(); i++) {
        if (ww[s][i] == e) continue;
        haku(ww[s][i], s);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k >> w;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            string x;
            cin >> x;
            s[i] += x;
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = i+1; j < k; j++) {
            int q = 0;
            for (int z = 0; z < n*m; z++) if (s[i][z] != s[j][z]) q++;
            if (q*w >= n*m) continue;
            v.push_back(make_pair(q*w, make_pair(i,j)));
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < k; i++) aa[i] = i;
    for (int i = 0; i < k; i++) ab[i] = 1;
    for (int i = 0; i < v.size(); i++) {
        int a = v[i].second.first;
        int b = v[i].second.second;
        if (sama(a, b)) continue;
        liita(a, b);
        c += v[i].first;
        r++;
        ww[a].push_back(b);
        ww[b].push_back(a);
    }
    int ok[1111] = {0};
    for (int i = 0; i < k; i++) {
        int a = aa[i];
        while (a != aa[a]) a = aa[a];
        if (ok[a]) continue;
        ok[a] = 1;
        c += n*m;
        haku(a, -1);
    }
    cout << c << "\n";
    for (int i = 0; i < va.size(); i++) {
        cout << va[i].first+1 << " " << va[i].second+1 << "\n";
    }
}