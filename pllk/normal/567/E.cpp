#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define M 823648117

int n, m, s, t;

int r[101010][3];

vector<int> v1[101010];
vector<int> p1[101010];
vector<int> v2[101010];
vector<int> p2[101010];

priority_queue<pair<ll,int>> q1, q2;

ll c1[101010];
ll c2[101010];
ll t1[101010];
ll t2[101010];
int x1[101010];
int x2[101010];

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        v1[a].push_back(b);
        p1[a].push_back(l);
        v2[b].push_back(a);
        p2[b].push_back(l);
        r[i][0] = a;
        r[i][1] = b;
        r[i][2] = l;
    }

    q1.push({0,s});
    q2.push({0,t});
    for (int i = 1; i <= n; i++) {
        t1[i] = 999999999999999LL;
        t2[i] = 999999999999999LL;
    }
    t1[s] = 0;
    t2[t] = 0;
    c1[s] = 1;
    c2[t] = 1;

    while (!q1.empty()) {
        auto s = q1.top();
        q1.pop();
        ll sm = -s.first;
        int ss = s.second;
        if (x1[ss]) continue;
        x1[ss] = 1;
        for (int i = 0; i < v1[ss].size(); i++) {
            int uu = v1[ss][i];
            ll pp = p1[ss][i];
            if (sm+pp > t1[uu]) continue;
            if (sm+pp == t1[uu]) {
                c1[uu] += c1[ss];
                c1[uu] %= M;
            } else {
                c1[uu] = c1[ss];
                t1[uu] = sm+pp;
                q1.push({-t1[uu],uu});
            }
        }
    }

    while (!q2.empty()) {
        auto s = q2.top();
        q2.pop();
        ll sm = -s.first;
        int ss = s.second;
        if (x2[ss]) continue;
        x2[ss] = 1;
        for (int i = 0; i < v2[ss].size(); i++) {
            int uu = v2[ss][i];
            ll pp = p2[ss][i];
            if (sm+pp > t2[uu]) continue;
            if (sm+pp == t2[uu]) {
                c2[uu] += c2[ss];
                c2[uu] %= M;
            } else {
                c2[uu] = c2[ss];
                t2[uu] = sm+pp;
                q2.push({-t2[uu],uu});
            }
        }
    }

    ll ee = t1[t];
    
    for (int i = 1; i <= m; i++) {
        if (t1[r[i][0]]+t2[r[i][1]]+r[i][2] == ee) {
            if ((c1[r[i][0]]*c2[r[i][1]])%M == c1[t]) {
                cout << "YES\n";
            } else if (r[i][2] > 1) {
                cout << "CAN 1\n";
            } else {
                cout << "NO\n";
            }
        } else if (t1[r[i][0]]+t2[r[i][1]]+1 < ee) {
            ll w = t1[r[i][0]]+t2[r[i][1]]+r[i][2]-ee;
            cout << "CAN " << w+1 << "\n";
        } else {
            cout << "NO\n";
        }
    }
}