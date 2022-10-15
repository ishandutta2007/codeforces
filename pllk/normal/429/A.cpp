#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> p[101010];
vector<int> t;

int x1[101010];
int x2[101010];

void haku(int k, int e, int m1, int m2, int s) {
    if (s%2 == 0 && x1[k]^m1 != x2[k]) {
        t.push_back(k);
        m1 = 1-m1;
    }
    if (s%2 == 1 && x1[k]^m2 != x2[k]) {
        t.push_back(k);
        m2 = 1-m2;
    }
    for (int i = 0; i < p[k].size(); i++) {
        if (p[k][i] == e) continue;
        haku(p[k][i], k, m1, m2, s+1);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    for (int i = 0; i < n; i++) cin >> x1[i+1];
    for (int i = 0; i < n; i++) cin >> x2[i+1];
    haku(1, -1, 0, 0, 0);
    cout << t.size() << endl;
    for (int i = 0; i < t.size(); i++) cout << t[i] << endl;
}