#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define TESTCASE

/*  original edge = 1 occ
    cnt number of occ, pq?




*/


int solve() {

    int N;
    cin >> N;
    vector<array<int, 3>> A(N - 2);
    map<pair<int, int>, int> mp;
    map<array<int, 3>, int> input;
    for (int i = 0; i + 2 < N; i++) {
        int a, b, c;
        cin >> A[i][0] >> A[i][1] >> A[i][2];
        A[i][0]--, A[i][1]--, A[i][2]--;
        sort(begin(A[i]), end(A[i]));
        mp[{A[i][0], A[i][1]}]++;
        mp[{A[i][0], A[i][2]}]++;
        mp[{A[i][1], A[i][2]}]++;
        input[A[i]] = i;
    }

    set<pair<int, int>> edge, cut;
    for (auto& i : mp) {
        if (i.second == 1) {
            edge.emplace(i.first);
        } else {
            cut.emplace(i.first);
        }
    }

    int fi = edge.begin()->first;
    int cur = fi;
    vector<int> poly;
    vector<vector<int>> G(N);
    vector<int> vis(N);

    for (auto& i : edge) {
        G[i.first].emplace_back(i.second);
        G[i.second].emplace_back(i.first);
    }

    function<void(int)> dfs = [&] (int n) {
        if (vis[n] == 1) {
            return;
        }
        vis[n] = 1;
        poly.emplace_back(n);
        for (auto i : G[n]) if (vis[i] == 0) dfs(i);
    };
    dfs(cur);

    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) {
        L[poly[i]] = poly[(i - 1 + N) % N];
        R[poly[i]] = poly[(i + 1 + N) % N];
    }

    vector<int> deg(N, 0);
    for (auto i : cut) {
        deg[i.first]++;
        deg[i.second]++;
    }
    
    // cout << "DEG: ";
    // for (auto i : deg) {
    //     cout << i << " ";
    // }
    // cout << "\n";

    int st = 0;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (deg[i] == 0) {
            q.emplace(i);
        }
    }
    vector<int> ans;
    while (ans.size() < N - 2) {
        st = q.front(); 
        q.pop();
        array<int, 3> qq;
        
        qq[0] = st;
        qq[1] = L[st];
        qq[2] = R[st];

        sort(begin(qq), end(qq));
        // cout << qq[0] << " " << qq[1] << " " << qq[2] << "\n";
        ans.emplace_back(input[qq]);

        deg[L[st]]--;
        deg[R[st]]--;
        int l = L[st], r = R[st];
        R[l] = r;
        L[r] = l;
        if (deg[L[st]] == 0) {
            st = L[st];
            q.emplace(st);
        } else if (deg[R[st]] == 0) {
            st = R[st];
            q.emplace(st);
        }
    }

    for (auto i : poly) {
        cout << i + 1 << " ";
    }
    cout << "\n";

    for (auto i : ans) {
        cout << i + 1 << " ";
    }
    cout << "\n";


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    #ifdef TESTCASE
    cin >> T;
    #else
    T = 1;
    #endif
    while (T--) {
        solve();
    }
    return 0;
}