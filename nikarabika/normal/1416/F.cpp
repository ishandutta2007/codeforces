//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 100 * 1000 + 10;
int dx[4] = {-1, -0, +0, +1};
int dy[4] = {-0, -1, +1, +0};
char dir_char[] = "ULRD";

struct Prob {
    int n, m;
    int **a;
    int **num;
    char **dir;

    vector<int> adj[maxn],
                madj[maxn];
    int match[maxn];
    bool mark[maxn];

    void add_edge(int u, int v) {
        //cerr << u << "<--->" << v << endl;
        adj[u].PB(v);
    }

    bool is_valid(int i, int j) {
        return 0 <= i and i < n and 0 <= j and j < m;
    }

    bool is_black(int id) {
        int i = id / m,
            j = id % m;
        for (int d = 0; d < 4; d++) {
            int ii = i + dx[d],
                jj = j + dy[d];
            if (is_valid(ii, jj) and a[ii][jj] < a[i][j])
                return false;
        }
        return true;
    }

    bool oddcell(int id) {
        int i = id / m,
            j = id % m;
        return (i + j) & 1;
    }

    bool evencell(int id) {
        return !oddcell(id);
    }

    bool dfs(int u) {
        //cout << "enter " << u << endl;
        mark[u] = true;
        for (auto v: adj[u]) {
            if (match[v] == -1) {
                match[u] = v;
                match[v] = u;
                return true;
            }
            if (mark[match[v]]) continue;
            if (dfs(match[v])) {
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        //cout << "exit  " << u << endl;
        return false;
    }

    int solve() {
        cin >> n >> m;
        {
            a = new int*[n];
            num = new int*[n];
            dir = new char*[n];
            for (int i = 0; i < n; i++) {
                a[i] = new int[m];
                num[i] = new int[m];
                dir[i] = new char[m];
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int d = 0; d < 4; d++) {
                    int ii = i + dx[d];
                    int jj = j + dy[d];
                    if (is_valid(ii, jj) and a[i][j] == a[ii][jj])
                        add_edge(i * m + j, ii * m + jj);
                }

        bool found;

        memset(match, -1, sizeof match);
        found = true;
        while (found) {
            memset(mark, false, sizeof mark);
            found = false;
            for (int i = 0; i < n * m; i++)
                if (oddcell(i) and !mark[i] and match[i] == -1 and is_black(i) and dfs(i))
                    found = true;
        }
        for (int i = 0; i < n * m; i++) {
            //cout << "match(" << i << ") = " << match[i] << endl;
            if (match[i] != -1)
                madj[i].PB(match[i]);
            else if (oddcell(i) and is_black(i))
                return cout << "NO\n", 0;
        }

        memset(match, -1, sizeof match);
        found = true;
        while (found) {
            memset(mark, false, sizeof mark);
            found = false;
            for (int i = 0; i < n * m; i++)
                if (evencell(i) and !mark[i] and match[i] == -1 and is_black(i) and dfs(i))
                    found = true;
        }
        for (int i = 0; i < n * m; i++) {
            //cout << "match(" << i << ") = " << match[i] << endl;
            if (match[i] != -1 and 
                    (sz(madj[i]) == 0 or madj[i][0] != match[i]))
                madj[i].PB(match[i]);
            if (evencell(i) and match[i] == -1 and is_black(i))
                return cout << "NO\n", 0;
        }

        memset(match, -1, sizeof match);
        memset(mark, false, sizeof mark);
        for (int u = 0; u < n * m; u++)
            if (sz(madj[u]) == 1 and !mark[u]) {
                vector<int> vec;
                int v = u,
                    prv = -1;
                vec.PB(v);
                do {
                    int cur = v;
                    v = madj[v][0] == prv ? madj[v][1] : madj[v][0];
                    prv = cur;
                    vec.PB(v);
                    mark[v] = true;
                } while (sz(madj[v]) == 2);
                //cout << "PATH: ";
                //for (auto u: vec)
                //    cout << u << ' ';
                //cout << endl;

                if (sz(vec) & 1) {
                    for (int i = !is_black(vec[0]); i + 1 < sz(vec); i += 2) {
                        match[vec[i + 0]] = vec[i + 1];
                        match[vec[i + 1]] = vec[i + 0];
                    }
                }
                else {
                    for (int i = 0; i < sz(vec); i += 2) {
                        match[vec[i + 0]] = vec[i + 1];
                        match[vec[i + 1]] = vec[i + 0];
                    }
                }
            }

        for (int u = 0; u < n * m; u++)
            if (!mark[u] and sz(madj[u]) == 2) {
                vector<int> vec;
                int v = u;
                do {
                    mark[v] = true;
                    vec.PB(v);
                    v = mark[madj[v][0]] ? madj[v][1] : madj[v][1];
                } while (v != u);
                //cout << "CYCLE: ";
                //for (auto u: vec)
                //    cout << u << ' ';
                //cout << endl;

                for (int i = 0; i < sz(vec); i += 2) {
                    match[vec[i + 0]] = vec[i + 1];
                    match[vec[i + 1]] = vec[i + 0];
                }
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int id = i * m + j;
                if (~match[id]) {
                    //cout << "final " << id << ' ' << match[id] << endl;
                    int ii = match[id] / m,
                        jj = match[id] % m;
                    num[i][j] = ((i + j) & 1) ? 1 : a[i][j] - 1;
                    for (int d = 0; d < 4; d++)
                        if (ii - i == dx[d] and jj - j == dy[d])
                            dir[i][j] = dir_char[d];
                }
                else {
                    assert(!is_black(id));
                    for (int d = 0; d < 4; d++) {
                        int ii = i + dx[d],
                        jj = j + dy[d];
                        if (is_valid(ii, jj) and a[ii][jj] < a[i][j]) {
                            num[i][j] = a[i][j] - a[ii][jj];
                            dir[i][j] = dir_char[d];
                        }
                    }
                }
            }
        cout << "YES\n";
        for (int i = 0; i < n; i++, cout << '\n')
            for (int j = 0; j < m; j++)
                cout << num[i][j] << ' ';
        for (int i = 0; i < n; i++, cout << '\n')
            for (int j = 0; j < m; j++)
                cout << dir[i][j] << ' ';
        return 0;
    }
};

int solve() {
    Prob p;
    return p.solve();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}