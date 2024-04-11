#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <stack>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int sz = 301, szp = 300 * 300 + 1;
int n, m, p;
int a[sz][sz], closestUp[sz][szp], closestDown[sz][szp];
vector<pii> adj[sz*sz];
int d[sz*sz];

inline int tn(int i, int j) {
    return m * i + j;
}

void scans() {
    foru(i, 0, n) {
        foru(j, 0, m) {
            if (a[i][j] != p) {
                int mytn = tn(i, j), lst = -1e9;
                ford(k, j - 1, 0) {
                    int tmp = closestUp[k][1 + a[i][j]];
                    if (tmp != -1 && tmp > lst) {
                        adj[mytn].push_back({ tn(tmp,k), abs(j - k) + abs(i - tmp) });
                        lst = tmp;
                    }
                }
                if (closestUp[j][a[i][j] + 1] != -1)
                    adj[mytn].push_back({ tn(closestUp[j][a[i][j] + 1], j), abs(i - closestUp[j][a[i][j] + 1]) });
                lst = -1e9;
                foru(k, j + 1, m) {
                    int tmp = closestUp[k][1 + a[i][j]];
                    if (tmp != -1 && tmp > lst) {
                        adj[mytn].push_back({ tn(tmp,k),abs(j - k) + abs(i - tmp) });
                        lst = tmp;
                    }
                }
            }
            closestUp[j][a[i][j]] = i;
        }
    }
    ford(i, n - 1, 0) {
        ford(j, m - 1, 0) {
            if (a[i][j] != p) {
                int mytn = tn(i, j), lst = 1e9;
                ford(k, j - 1, 0) {
                    int tmp = closestDown[k][1 + a[i][j]];
                    if (tmp != -1 && tmp < lst) {
                        adj[mytn].push_back({ tn(tmp,k), abs(j - k) + abs(i - tmp) });
                        lst = tmp;
                    }
                }
                if (closestDown[j][a[i][j] + 1] != -1)
                    adj[mytn].push_back({ tn(closestDown[j][a[i][j] + 1], j), abs(i - closestDown[j][a[i][j] + 1]) });
                lst = 1e9;
                foru(k, j + 1, m) {
                    int tmp = closestDown[k][1 + a[i][j]];
                    if (tmp != -1 && tmp < lst) {
                        adj[mytn].push_back({ tn(tmp,k),abs(j - k) + abs(i - tmp) });
                        lst = tmp;
                    }
                }
            }
            closestDown[j][a[i][j]] = i;
        }
    }
}

void dijk() {
    foru(i, 0, n * m)d[i] = 1e9;
    set<pii> q;
    foru(i, 0, n) {
        foru(j, 0, m) {
            if (a[i][j] == 1) {
                d[tn(i,j)] = i + j;
                q.insert({ d[tn(i,j)],tn(i,j) });
            }
        }
    }
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({ d[to], to });
                d[to] = d[v] + len;
                q.insert({ d[to], to });
            }
        }
    }
}

int main() {
    fast;
    cin >> n >> m >> p;
    foru(i, 0, n) {
        foru(j, 0, m)
            cin >> a[i][j];
    }
    foru(i, 0, sz) {
        foru(j, 0, szp)closestUp[i][j] = closestDown[i][j] = -1;
    }
    scans();
    dijk();
    foru(i, 0, n) {
        foru(j, 0, m) {
            if (a[i][j] == p)cout << d[tn(i,j)];
        }
    }
    return 0;
}