#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define INF 999999999

int n;
int a[101010];
set<int> s;
map<int,int> m;
int b[303030];
int d[303030];

#define N (1<<18)
int p[2*N];

void setVal(int k, int x) {
    k += N;
    p[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        p[k] = min(p[2*k],p[2*k+1]);
    }
}

int getMin(int a, int b) {
    a += N; b += N;
    int r = p[a];
    while (a <= b) {
        if (a%2 == 1) r = min(r,p[a++]);
        if (b%2 == 0) r = min(r,p[b--]);
        a /= 2; b /= 2;
    }
    return r;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
        if (a[i]%2 == 0) s.insert(a[i]/2-1);
        else s.insert(a[i]/2);
    }
    int c = 0;
    for (auto x : s) {
        c++;
        m[x] = c;
    }
    for (int i = 0; i <= c; i++) setVal(i,INF);
    for (int i = 1; i <= n; i++) {
        b[i] = a[i];
        b[i+n] = a[i];
        b[i+2*n] = a[i];
    }
    vector<pair<int,int>> s;
    for (int i = 3*n; i >= 1; i--) {
        int x = b[i]%2 == 0 ? b[i]/2-1 : b[i]/2;
        int u = getMin(0,m[x]);
        d[i] = u;
        while (s.size() && s.back().first <= b[i]) s.pop_back();
        if (s.size()) d[i] = min(d[i],d[s.back().second]);
        s.push_back({b[i],i});
        setVal(m[b[i]],i);
    }
    for (int i = 1; i <= n; i++) {
        cout << (d[i] == INF ? -1 : d[i]-i) << " ";
    }
    cout << "\n";
}