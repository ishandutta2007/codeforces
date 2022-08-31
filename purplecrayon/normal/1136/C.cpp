#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 5e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int a[MAXN][MAXN], b[MAXN][MAXN];
vector<int> va[2*MAXN], vb[2*MAXN];

void solve(){
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> b[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) 
        va[i+j].push_back(a[i][j]), vb[i+j].push_back(b[i][j]);
    for (int i = 0; i <= n+m; i++) {
        sort(va[i].begin(), va[i].end()), sort(vb[i].begin(), vb[i].end());
        if (va[i] != vb[i]){
            cout << no;
            return;
        }
    }
    cout << yes;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve(); 
}