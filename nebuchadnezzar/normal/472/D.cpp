#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define all(_x) _x.begin(), _x.end()
#define szof(_x) (int) _x.size()

using namespace std;
typedef long long LL;
const int MAXN = 2005;

const int MAX_MEM = (int)215 * 1024 * 1024;

int mpos, max_mpos;
char memory[MAX_MEM];                        

inline void * operator new (size_t n) {
  char *res = memory + mpos;
  mpos += n;
  assert(mpos <= MAX_MEM);
  return (void *)res;
}

inline void operator delete (void *) { }

int n, matrix[MAXN][MAXN], new_matrix[MAXN][MAXN];
vector <pair <int, int> > graph[MAXN];
bool used[MAXN];

vector <pair <int, int> > dfs(int v) {
    used[v] = true;
    int num_child = 0;
    vector <pair <int, int> > down[szof(graph[v])];
    int c = 0;
    for (int i = 0; i < szof(graph[v]); ++i) {
        if (!used[graph[v][i].ff]) {
            ++num_child;
            down[c] = dfs(graph[v][i].ff);
            for (int j = 0; j < szof(down[c]); ++j) {
                down[c][j].ss += graph[v][i].ss;
                new_matrix[down[c][j].ff][v] = down[c][j].ss;
                new_matrix[v][down[c][j].ff] = down[c][j].ss;
            }
            ++c;
        }
    }
    vector <pair <int, int> > ret;
    for (int i = 0; i < num_child; ++i) {
        for (int j = i + 1; j < num_child; ++j) {
            for (int i2 = 0; i2 < szof(down[i]); ++i2) {
                for (int j2 = 0; j2 < szof(down[j]); ++j2) {
                    new_matrix[down[i][i2].ff][down[j][j2].ff] = down[i][i2].ss + down[j][j2].ss;
                    new_matrix[down[j][j2].ff][down[i][i2].ff] = down[i][i2].ss + down[j][j2].ss;
                }
            }
        }
        for (int j = 0; j < szof(down[i]); ++j) {
            ret.puba(mapa(down[i][j].ff, down[i][j].ss));
        }
    }
    ret.puba(mapa(v, 0));
    /*
    cout << v << endl;
    for (int i = 0; i < szof(ret); ++i) {
        cout << ret[i].ff << "#" << ret[i].ss << " ";
    }
    cout << endl;
    */
    return ret;
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int num;
            cin >> num;
            matrix[i][j] = matrix[j][i] = num;
        }
    }

    priority_queue <pair <int, pair <int, int> > > q;
    q.push(mapa(0, mapa(0, 0)));
    

    while (szof(q)) {       
        pair <int, pair <int, int> > p;
        do {
            p = q.top();
            q.pop();
        } while (szof(q) && used[p.ss.ss]);
        if (used[p.ss.ss]) {
            break;
        }
        p.ff *= -1;
        if (p.ss.ss != p.ss.ff) {
            graph[p.ss.ff].puba(mapa(p.ss.ss, p.ff));
            graph[p.ss.ss].puba(mapa(p.ss.ff, p.ff));
        }
        used[p.ss.ss] = true;

        for (int i = 0; i < n; ++i) {
            if (!used[i] && matrix[p.ss.ss][i] != 0) {
                q.push(mapa(-matrix[p.ss.ss][i], mapa(p.ss.ss, i)));                
            }
        }
    }
    
    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < szof(graph[i]); ++j) {
            cout << graph[i][j].ff << "#" << graph[i][j].ss << " ";
        }
        cout << endl;
    }
    */
    memset(used, 0, sizeof used);
    dfs(0);

    bool flag = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //cout << new_matrix[i][j] << " ";
            if (matrix[i][j] != new_matrix[i][j]) {
                flag = false;
                break;
            }
        }
        //cout << endl;
        if (!flag) {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "YES\n";
    } else {
      cout << "NO\n";
    }

    return 0;
}