#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
vector<int> v[101010];
vector<int> r1, r2;
int rw[101010];
int c[101010];
ll t;
int w[101010];

void dfs(int s, int e) {
    c[s] = 1;
    for (auto u : v[s]) {
        if (u == e) continue;
        dfs(u,s);
        c[s] += c[u];
    }
    r1.push_back(s);
    r2.push_back(s);
    rw[s] = r1.size()-1;
    if (e != 0) t += min(c[s],n-c[s]);
}

int di = -1;

void dfs2(int s, int e) {
    if (di == -1 || di == n-1 || c[s] >= n-c[s]) di = rw[s];
    int pc = 0, pu = 0;
    for (auto u : v[s]) {
        if (u == e) continue;
        if (c[u] > pc) {pc = c[u]; pu = u;}
    }
    if (pu != 0) dfs2(pu,s);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    if (n%2 == 1) {
        dfs2(1,0);
        swap(r2[di],r2[n-1]);
    }
    for (int i = 0; i < n/2; i++) {
        swap(r2[i],r2[i+n/2]);
    }
    for (int i = 0; i < n; i++) {
        w[r2[i]] = r1[i];
    }
    cout << 2*t << "\n";
    for (int i = 1; i <= n; i++) cout << w[i] << " ";
    cout << "\n";
}