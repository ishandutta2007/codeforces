#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
const int max_n = 2e5 + 3;

int n, k;
set<int> gr[max_n];

void solve() {
    cin >> n >> k;
    for(int i = 0;i < n;i++) {
        gr[i].clear();
    }

    set<int> leaf;

    for(int i = 0;i < n - 1;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace(v2);
        gr[v2].emplace(v1);
    }

    for(int i = 0;i < n;i++) if (gr[i].size() == 1) leaf.emplace(i);

    int res = 0;

    map<int, vector<int>> a;
    while(leaf.size()) {
        vector<int> check_v;
        for(int i : leaf) {
            //cout << i << " ";
            int to = *gr[i].begin();
            check_v.emplace_back(to);
            gr[i].clear();
            a[to].emplace_back(i);
        }
        //cout << endl;
        leaf.clear();

        for(int v : check_v) {

            vector<int> &temp = a[v];
            while(temp.size() >= k) {
                for(int it = 0;it < k;it++) {
                    int to = temp.back();
                    temp.pop_back();
                    gr[v].erase(to);
                }
                res++;
            }
            
            if (gr[v].size() == 1) leaf.emplace(v);
        }
    }

    cout << min(res, (n - 1) / k) << endl;
}


signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}