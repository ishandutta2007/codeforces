#include <bits/stdc++.h>
#define testcase int TESTCASE; cin >> TESTCASE; while (TESTCASE--)
#define db(x) cout << #x << " is " << x << "\n"
using namespace std;
using lint = long long;

map<int, vector<int>> ls;
vector<int> P;
map<int, int> freq;
int cur = 0;
int dir = 1;

void dfs(int n) {
    if (n == -1) return;
    P[cur] = n;
    cur += dir;
    int cand = -1;
    freq[n]--;
    for (auto i : ls[n]) {
        freq[i]--;
        if (freq[i] == 1) {
            if (cand != -1) return;
            cand = i;
        }
    }
    dfs(cand);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<array<int, 3>> T(N - 2, array<int, 3>());    
    P.resize(N, -1);

    map<pair<int, int>, pair<int, int>> mp;
    vector<int> vis(N + 1, 0);

    for (int i = 0; i < N - 2; i++) {
        cin >> T[i][0] >> T[i][1] >> T[i][2];
        freq[T[i][0]]++;
        freq[T[i][1]]++;
        freq[T[i][2]]++;
        ls[T[i][0]].emplace_back(T[i][1]);
        ls[T[i][0]].emplace_back(T[i][2]);
        ls[T[i][1]].emplace_back(T[i][0]);
        ls[T[i][1]].emplace_back(T[i][2]);
        ls[T[i][2]].emplace_back(T[i][0]);
        ls[T[i][2]].emplace_back(T[i][1]);
        
    }

    int cnt = 0;
    for (int i = 1; i <= N && cnt < 2; i++) {
        if (freq[i] == 1) {
            dfs(i);
            cnt++;
            freq.clear(); ls.clear();
            cur = N - 1;
            dir = -1;
            break;
        }
    }

    for (int i = 0; i < N - 2; i++) {
        freq[T[i][0]]++;
        freq[T[i][1]]++;
        freq[T[i][2]]++;
        ls[T[i][0]].emplace_back(T[i][1]);
        ls[T[i][0]].emplace_back(T[i][2]);
        ls[T[i][1]].emplace_back(T[i][0]);
        ls[T[i][1]].emplace_back(T[i][2]);
        ls[T[i][2]].emplace_back(T[i][0]);
        ls[T[i][2]].emplace_back(T[i][1]);
        
    }
    
    cur = N - 1;
    dir = -1;
    for (int i = N; i >= 1 && cnt < 2; i--) {
        if (freq[i] == 1) {
            dfs(i);
            cnt++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (P[i] != -1) vis[P[i]] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            for (int j = 0; j < N; j++) {
                if (P[j] == -1) {
                    P[j] = i;
                    break;
                }
            }
            break;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << P[i] << " ";
    }
    cout << "\n";

}