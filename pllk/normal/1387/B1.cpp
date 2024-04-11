#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v[101010];
int cc;
int p[101010];

void add(int a, int b, int c) {
    p[a] = b;
    cc += c;
}

int lol(int s, int e) {
    vector<int> f;
    for (auto u : v[s]) {
        if (u == e) continue;
        int x = lol(u,s);
        if (x == 1) f.push_back(u);
    }
    if (f.size() == 0) return 1;
    int k = f.size();
    if (k%2 == 0) {
        add(s,f[k-1],1);
        add(f[k-1],f[k-2],2);
        add(f[k-2],s,1);
        k -= 2;
    } else {
        add(s,f[k-1],1);
        add(f[k-1],s,1);
        k--;
    }
    for (int i = 0; i+1 < k; i += 2) {
        add(f[i],f[i+1],2);
        add(f[i+1],f[i],2);
    }
    return 0;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int x = lol(1,0);
    if (x == 1) {
        for (int i = 1; i <= n; i++) {
            if (p[i] == v[1][0]) p[i] = 1;
        }
        add(1,v[1][0],1);
        cc++;
    }
    cout << cc << "\n";
    for (int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << "\n";
}