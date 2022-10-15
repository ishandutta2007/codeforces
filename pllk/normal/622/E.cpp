#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> p[505050];
vector<int> v;

void haku(int s, int e, int c) {
    for (int i = 0; i < p[s].size(); i++) {
        if (p[s][i] != e) haku(p[s][i],s,c+1);
    }
    if (p[s].size() == 1) v.push_back(c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    int u = 0;
    for (int i = 0; i < p[1].size(); i++) {
        v.clear();
        haku(p[1][i],1,1);
        sort(v.begin(),v.end());
        int a = 0;
        for (int j = 0; j < v.size(); j++) {
            a = max(a+1,v[j]);
        }
        u = max(u,a);
    }
    cout << u << "\n";
}