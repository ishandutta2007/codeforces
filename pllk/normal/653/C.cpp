#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n;
int t[202020];
int c[202020];
vector<int> v;
int z;
set<pair<int,int>> q;

bool lol(int x) {
    if (x < 1 || x > n-1) return false;
    if (x%2 == 1 && t[x] < t[x+1]) return false;
    if (x%2 == 0 && t[x] > t[x+1]) return false;
    return true;
}

bool ok(int b) {
    vector<int> u = v;
    u.push_back(b-1);
    u.push_back(b);
    u.push_back(b+1);
    for (int i = 0; i < u.size(); i++) {
        if (lol(u[i]-2)) return false;
        if (lol(u[i]-1)) return false;
        if (lol(u[i])) return false;
        if (lol(u[i]+1)) return false;
        if (lol(u[i]+2)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n-1; i++) {
        if (i%2 == 1 && t[i] < t[i+1]) continue;
        if (i%2 == 0 && t[i] > t[i+1]) continue;
        if (!c[i]) {c[i] = 1; v.push_back(i);}
        if (!c[i+1]) {c[i+1] = 1; v.push_back(i+1);}
    }
    if (v.size() > 10) {
        cout << "0\n";
        return 0;
    }
    for (int x = 0; x < v.size(); x++) {
        for (int b = 1; b <= n; b++) {
	    int a = v[x];
            swap(t[a],t[b]);
            if (ok(b)) {
                int ua = a;
                int ub = b;
                if (ua > ub) swap(ua,ub);
                if (!q.count({ua,ub})) {
                    z++;
                    q.insert({ua,ub});
                }
            }
            swap(t[a],t[b]);
        }
    }
    cout << z << "\n";
}