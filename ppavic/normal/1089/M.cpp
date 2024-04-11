#include <bits/stdc++.h>

using namespace std;

const int maxn = 10;

int n;

bool adj[maxn][maxn];
bool rdj[maxn][maxn];
bool ndj[maxn][maxn];

vector<int> topo;

bool bio[maxn];

int cur_scc;
int scc[maxn];
vector<int> v_of_scc[maxn];

void dfs1(int i) {
    bio[i] = true;

    for(int j = 1; j <= n; j++) {
        if(!bio[j] && adj[i][j]) {
            dfs1(j);
        }
    }

    topo.push_back(i);
}

void dfs2(int i) {
    scc[i] = cur_scc;
    v_of_scc[scc[i]].push_back(i);

    for(int j = 1; j <= n; j++) {
        if(!scc[j] && rdj[i][j]) {
            dfs2(j);
        }
    }
}

void dfs3(int i) {
    bio[i] = true;

    for(int j = 1; j <= cur_scc; j++) {
        if(!bio[j] && ndj[i][j]) {
            dfs3(j);
        }
    }

    topo.push_back(i);
}

int x, y, z;
int cnt_tunnel = 0;
int _floor[maxn];
char c[1000][3][25];

void solve() {
    x = 4 + 2 * cnt_tunnel;
    y = 3;
    z = 2 * cur_scc - 1;

    // pocetni katovi
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            for(int h = 0; h < z; h++) {
                c[i][j][h] = '.';
            }
        }
    }

    for(int i = 0; i < cur_scc; i++) {
        _floor[topo[i]] = 2 * i;
    }

    for(int h = 1; h < z; h += 2) {
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                c[i][j][h] = '#';
            }
        }
    }

    // tuneli

    for(int h = 0; h < z; h += 2) {
        for(int i = 0; i < cnt_tunnel; i++) {
            c[3 + 2 * i + 0][0][h] = '#';
            c[3 + 2 * i + 1][0][h] = '#';
            c[3 + 2 * i + 2][0][h] = '#';
            c[3 + 2 * i + 1][1][h] = '#';
        }
    }

    // busi tunele >:)

    int cur_tun = 4;

    for(int i = 1; i <= cur_scc; i++) {
        for(int j = 1; j <= cur_scc; j++) {
            if(ndj[i][j] && i != j) {
                c[cur_tun][1][_floor[i]] = '.';
                c[cur_tun][1][_floor[j]] = '.';

                for(int h = min(_floor[i], _floor[j]); h <= max(_floor[i], _floor[j]); h++) {
                    c[cur_tun][0][h] = '.';
                }

                cur_tun += 2;
            }
        }
    }

    // dodaj spawnove

    for(int i = 1; i <= cur_scc; i++) {
        for(int id : v_of_scc[i]) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    if(c[j][k][_floor[i]] == '.') {
                        c[j][k][_floor[i]] = '0' + id;
                        goto out;
                    }
                }
            }

            out:;
        }
    }

    // isprintaj kurce

    cout << x << " " << y << " " << z << "\n";

    for(int h = z - 1; h >= 0; h--) {
        for(int j = 0; j < y; j++) {
            for(int i = 0; i < x; i++) {
                cout << c[i][j][h];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            rdj[j][i] = adj[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!bio[i]) {
            dfs1(i);
        }
    }

    reverse(topo.begin(), topo.end());

    for(int i : topo) {
        if(!scc[i]) {
            cur_scc++;
            dfs2(i);
        }
    }

//    cout << "scc: ";
//    for(int i = 1; i <= n; i++) {
//        cout << scc[i] << " ";
//    }
//    cout << endl;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ndj[scc[i]][scc[j]] |= adj[i][j];
        }
    }

//    cout << "novi graf:" << endl;
    for(int i = 1; i <= cur_scc; i++) {
        for(int j = 1; j <= cur_scc; j++) {
            if(i != j && ndj[i][j]) {
                cnt_tunnel++;
            }
//            cout << ndj[i][j] << " ";
        }
//        cout << endl;
    }
//    cout << endl;

    memset(bio, 0, sizeof bio);
    topo.clear();

    for(int i = 1; i <= cur_scc; i++) {
        if(!bio[i]) {
            dfs3(i);
        }
    }

//    reverse(topo.begin(), topo.end());

//    cout << "topo: ";
//    for(int i : topo)
//        cout << i << " ";

    solve();

    return 0;
}