#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
const int max_n = 1e5 + 1;

int n;
vector<pii> gr[max_n];
vector<pii> num[max_n];

vector<int> used;
void dfs(int v) {
    used.emplace_back(v);
    for(auto i : gr[v]) {
        num[i.first].emplace_back(-num[v][0].first, i.second - num[v][0].second);
        if (num[i.first].size() == 1) dfs(i.first);
    }
}

bool have_sol = true;

double eq(pii a, pii b) {
    if (a.first == b.first) {
        if (a.second != b.second) have_sol = false;
        return inf;
    }
    return (double) (b.second - a.second) / (a.first - b.first);
}

double eps = 1e-6;

bool eq(double a, double b) {
    return abs(a - b) < eps;
}

void solve() {
    int m;
    cin >> n >> m;
    vector<double> res(n);
    for(int i = 0;i < m;i++) {
        int v1, v2, t;
        cin >> v1 >> v2 >> t;
        v1--; v2--;
        gr[v1].emplace_back(v2, t);
        gr[v2].emplace_back(v1, t);
    }


    for(int start = 0;start < n;start++) {
        if (num[start].size() >= 1) continue;
        num[start].emplace_back(1, 0);
        dfs(start);
        double a = inf;
        for(int i : used) {
            pii v = num[i][0];
            for(pii to : num[i]) {
                double temp = eq(v, to);
                //cout << v.first << " " << v.second << " " << to.first << " " << to.second << " " << temp << endl;
                if (temp != inf) {
                    if (!eq(a, inf) && !eq(a, temp)) have_sol = false;
                    a = temp;
                }
            }
        }

        //cout << a << endl;

        vector<int> ver;
        for(int i : used) ver.emplace_back(-num[i][0].first * num[i][0].second);

        sort(ver.begin(), ver.end());

        if (eq(a, inf)) a = ver[ver.size() / 2];

        for(int i : used) {
            //cout << i + 1 << " " << num[i][0].first << " " << num[i][0].second << endl;
            res[i] = a * num[i][0].first + num[i][0].second;
        }

        used.clear();
    }

    if (!have_sol) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for(double i : res) cout << i << " ";
    }
}





signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}