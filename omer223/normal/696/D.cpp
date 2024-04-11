#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define chkmin(a, b) (a = ((a > b) ? b : a))
#define chkmax(a, b) (a = ((a < b) ? b : a))

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <memory>
#include <numeric>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, int> pdi;
typedef vector<vector<ll>> mat;

const int sz = 2e2 + 5;
int a[sz];
string strorig[sz];
int n;
ll l;
map<string, int> nd, ndorig;
vector<string> strs;
int sc[sz];

void comp(string st) {
    if (nd.count(st))return;
    int crsz = strs.size();
    nd[st] = crsz;
    strs.push_back(st);
    while (!st.empty()) {
        sc[crsz] += ndorig[st];
        st.erase(st.begin());
    }
}

ll adj[sz][sz];

void calcadj(string s) {
    int idx = nd[s];
    foru(cidx, 0, 26) {
        char c = 'a' + cidx;
        string t = s + c;
        while (!nd.count(t)) {
            t.erase(t.begin());
        }
        int ndt = nd[t];
        adj[idx][ndt] = sc[ndt];
    }
}

mat matmul(mat a, mat b) {
    int m = a.size();
    mat c(m, vector<ll>(m, -1));
    foru(i, 0, m) {
        foru(j, 0, m) {
            foru(k, 0, m) {
                if (a[i][k] != -1 && b[k][j] != -1)chkmax(c[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return c;
}

mat matpow(ll ex) {
    int m = strs.size();
    mat mt(m, vector<ll>(m, -1)), cur = mt;
    foru(i, 0, m) {
        foru(j, 0, m)mt[i][j] = adj[i][j];
        cur[i][i] = 0;
    }
    while (ex) {
        if (ex & 1)cur = matmul(cur, mt);
        ex >>= 1;
        mt = matmul(mt, mt);
    }
    return cur;
}

int main() {
    fast;
    cin >> n >> l;
    foru(i, 0, n)cin >> a[i];
    nd[""] = 0;
    strs.push_back("");
    foru(i, 0, n) {
        cin >> strorig[i];
        ndorig[strorig[i]] += a[i];
    }
    foru(i, 0, n) {
        string st = "";
        for (char c : strorig[i]) {
            st.push_back(c);
            comp(st);
        }
    }
    int m = strs.size();
    foru(i, 0, m) {
        foru(j, 0, m)adj[i][j] = -1;
    }
    for (string s : strs) {
        calcadj(s);
    }
    mat mt = matpow(l);
    ll ans = 0;
    foru(i, 0, strs.size())chkmax(ans, mt[0][i]);
    cout << ans;
    return 0;
}