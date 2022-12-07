#include <bits/stdc++.h>
#define long long long

using namespace std;

int f[55][1<<10];
int nxt[55][1<<10][55];
int go[11][115][55];
int deg[55][1<<10];
pair<int,int> pre[55][1<<10];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        int n; cin >> n;
        vector<string> a(n);
        

        map<char, int> ind;
        vector<char> alphabet;
        for(int i = 0; i < 26; ++i) {
            ind['a' + i] = alphabet.size();
            alphabet.push_back('a' + i);
            ind['A' + i] = alphabet.size();
            alphabet.push_back('A' + i);
        }

        // pos['A'][i]
        vector<vector<vector<int>>> pos(alphabet.size(), vector<vector<int>>(n));
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            for(int j = 0; j < a[i].size(); ++j) {
                pos[ind[a[i][j]]][i].push_back(j);
            }
        }
        
        memset(f, 0, sizeof(f));
        memset(go, -1, sizeof(go));
        memset(nxt, -1, sizeof(nxt));
        memset(deg, 0, sizeof(deg));

        for(int i = 0; i < n; ++i) {
            for(int j = a[i].size() - 1; j >= 0; --j) {
                for(int k = 0; k < alphabet.size(); ++k) {
                    go[i][j][k] = go[i][j+1][k];
                }
                go[i][j][ind[a[i][j]]] = j;
            }
        }

        for(int i = 0; i < alphabet.size(); ++i) {
            for(int msk = 0; msk < (1 << n); ++msk) {
                vector<int> positions;



                for(int k = 0; k < n; ++k) {
                    if ((msk >> k & 1) >= pos[i][k].size()) {
                        break;
                    }
                    positions.push_back(pos[i][k][msk >> k & 1]);
                }

                if (positions.size() != n) {
                    continue;
                }

                for(int j = 0; j < alphabet.size(); ++j) {

                    int flag = 1, nwmask = 0;
                    for(int i = 0; i < n; ++i) {
                        if (go[i][positions[i] + 1][j] == -1) {
                            flag = 0;
                            break;
                        }
                        nwmask |= (go[i][positions[i] + 1][j] != pos[j][i][0]) << i;
                    }    
                    if (flag) {
                        nxt[i][msk][j] = nwmask;
                        deg[j][nwmask]++;
                    }
                }
            }
        }

        for(int i = 0; i < alphabet.size(); ++i) {
            int flag = 1;
            for(int j = 0; j < n; ++j) {
                if (pos[i][j].size() == 0) flag = 0;
            }
            f[i][0] = flag;
        }

        vector<pair<int,int>> que;
        for(int i = 0; i < alphabet.size(); ++i) {
            for(int msk = 0; msk < (1 << n); ++msk) {
                if (deg[i][msk] == 0) que.emplace_back(i, msk);
            }
        }

        int ans = 0;

        auto maximize = [&](int i, int msk, int j, int nwmsk) -> void {
            if (f[i][msk] + 1 > f[j][nwmsk]) {
                f[j][nwmsk] = f[i][msk] + 1;
                pre[j][nwmsk] = make_pair(i, msk);
            }
        };

        pair<int,int> state = make_pair(0, 0);

        while(!que.empty()) {
            auto [i, msk] = que.back(); que.pop_back();
            
            ans = max(ans, f[i][msk]);
            if (f[i][msk] == ans) state = make_pair(i, msk);

            for(int j = 0; j < alphabet.size(); ++j) {
                if (nxt[i][msk][j] == -1) continue;
                int nwmsk = nxt[i][msk][j];
                maximize(i, msk, j, nwmsk);
                deg[j][nwmsk]--;
                if (deg[j][nwmsk] == 0) {
                    que.emplace_back(j, nwmsk);
                }
            }
        }

        cout << ans << "\n";
        if (ans == 0) continue;
        else {
            auto [i, msk] = state;
            string res;
            for(int t = 0; t < ans; ++t) {
                res += alphabet[i];
                auto [j, nwmsk] = pre[i][msk];
                i = j;
                msk = nwmsk;
            }
            reverse(res.begin(), res.end());
            cout << res << "\n";
        }
    }

    return 0;
}