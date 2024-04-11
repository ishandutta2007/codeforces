#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1e18;
const int mod = 1e9 + 7;

const int MAX_N = 1000010;

vector<int> drogi[MAX_N];
vector<int> v;

int dfs(int gdzie = 1, int skad = 1, int dl = 0) {
    int pod = 0;
    
    for (int i : drogi[gdzie]) {
        if (i == skad) continue;
        pod += dfs(i, gdzie, dl + 1);
    }
    
    v.push_back(dl - pod);
    
    return pod + 1;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    for (int a, b, i = 1; i < n; i++) {
        cin >> a >> b;
        drogi[a].push_back(b);
        drogi[b].push_back(a);
    }
    
    dfs();
    sort(ALL(v));
    reverse(ALL(v));
    
    int res = 0;
    for (int i = 0; i < k; i++) {
        res += v[i];
    }
    
    cout << res;
    
    return 0;
}/*

*/