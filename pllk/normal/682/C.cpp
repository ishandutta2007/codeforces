#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
int a[101010];
vector<int> v[101010];
vector<ll> p[101010];

int c;

void haku(int s, int e, ll z, int x) {
    if (z > a[s]) x = 1;
    if (x) c++;
    for (int i = 0; i < v[s].size(); i++) {
        if (v[s][i] == e) continue;
        haku(v[s][i], s, max(p[s][i],z+p[s][i]), x);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[i+1].push_back(a);
        v[a].push_back(i+1);
        p[i+1].push_back(b);
        p[a].push_back(b);
    }
    haku(1,0,0,0);
    cout << c << "\n";
}