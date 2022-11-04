#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

inline void mod(int &x, int p) {
    if(x >= p)
        x -= p;
}

inline int lgput(int a, int b, int p) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (1LL * ans * a) % p;
        b >>= 1;
        a = (1LL * a * a) % p;
    }
    return ans;
}

vector < pair <int, int> > path1[31623];
map <int, bool> vis;

inline bool bfs1(int u, int p) {
    int nr = sqrt(p);
    while(nr > 0) {
        nr--;
        int nod = u;
        vis[nod] = 1;
        for(int i = 1; i <= 100; i++) {
            int op = rand() % 3 + 1;
            if(op == 1) {
                nod++;
                mod(nod, p);
            }
            if(op == 2) {
                nod += p - 1;
                mod(nod, p);
            }
            if(op == 3) {
                nod = lgput(nod, p - 2, p);
            }
            path1[nr].push_back({nod, op});
            vis[nod] = 1;
        }
    }
}

vector <int> sol;

inline void solve(int nod, vector < pair <int, int> > path) {
    int i = 0;
    while(1) {
        bool ok = 0;
        for(auto it : path1[i]) {
            if(it.first == nod) {
                ok = 1;
                break;
            }
        }
        if(ok) {
            for(auto it : path1[i]) {
                sol.push_back(it.second);
                if(it.first == nod) {
                    break;
                }
            }
            reverse(path.begin(), path.end());
            for(auto it : path) {
                int op = 3;
                if(it.second == 1) {
                    op = 2;
                }
                if(it.second == 2) {
                    op = 1;
                }
                sol.push_back(op);
            }
            break;
        }
        i++;
    }
    cout << sol.size() << "\n";
    for(auto it : sol) {
        cout << it << " ";
    }
}

inline bool bfs2(int u, int p) {
    int nod = u;
    vector < pair <int, int> > path;
    if(vis[u]) {
        solve(u, path);
        return 1;
    }
    for(int i = 1; i <= 100; i++) {
        int op = rand() % 3 + 1;
        if(op == 1) {
            nod++;
            mod(nod, p);
        }
        if(op == 2) {
            nod += p - 1;
            mod(nod, p);
        }
        if(op == 3) {
            nod = lgput(nod, p - 2, p);
        }
        path.push_back({nod, op});
        if(vis[nod]) {
            solve(nod, path);
            return 1;
        }
    }
    return 0;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int u, v, p;
    ios::sync_with_stdio(false);
    srand(time(NULL));
    cin >> u >> v >> p;
    bfs1(u, p);
    while(!bfs2(v, p)) {

    }
    //cin.close();
    //cout.close();
    return 0;
}