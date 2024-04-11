#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

#define N (1<<20)

int p[2*N];

void setVal(int k, int x) {
    k += N;
    p[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        p[k] = p[2*k]+p[2*k+1];
    }
}

int getSum(int a, int b) {
    a += N; b += N;
    int s = 0;
    while (a <= b) {
        if (a%2 == 1) s += p[a++];
        if (b%2 == 0) s += p[b--];
        a /= 2; b /= 2;
    }
    return s;
}

int n, m;

int main() {
    cin >> n >> m;
    vector<vector<int>> e;
    for (int i = 1; i <= n; i++) {
        int y, a, b;
        cin >> y >> a >> b;
        e.push_back({a,0,y});
        e.push_back({b,2,y});
    }
    for (int i = 1; i <= m; i++) {
        int x, a, b;
        cin >> x >> a >> b;
        e.push_back({x,1,a,b});
    }
    e.push_back({(int)1e6,1,0,(int)1e6});
    sort(e.begin(),e.end());
    setVal(0,1);
    setVal(1e6,1);
    set<int> f;
    ll r = 0;
    for (int i = 0; i < e.size(); i++) {
        if (e[i][1] == 0) {
            if (e[i][0] == 0) {
                setVal(e[i][2],1);
            } else {
                f.insert(e[i][2]);
            }
        }
        if (e[i][1] == 1) {
            int z = getSum(e[i][2],e[i][3]);
            if (z > 1) r += z-1;
            auto it = f.lower_bound(e[i][2]);
            while (it != f.end()) {
                auto a = *it;
                if (a > e[i][3]) break;
                it++;
                setVal(a,1);
                f.erase(a);
            }
        }
        if (e[i][1] == 2) {
            setVal(e[i][2],0);
        }
    }
    cout << r << "\n";
}