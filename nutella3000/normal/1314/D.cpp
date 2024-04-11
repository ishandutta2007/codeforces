#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
typedef long double ld;

const int inf = 1e15;
const int max_n = 81, max_k = 11;

int n, k;
int gr[max_n][max_n];
int dp[max_n][max_n][max_n];

vector<int> vert;
int ve[max_n];

int res = inf;

void check() {
    int new_res = 0;

    for(int i : vert)
        ve[i] = true;

    for(int i = 0;i < sz(vert) - 1;i++) {
        int v = vert[i];
        int to = vert[i + 1];

        int num = 0;
        while(num < n && ve[dp[v][to][num]]) 
            num++;

        if (num == n) {
            for(int i : vert) {
                ve[i] = false;
            }
            return;
        }

        num = dp[v][to][num];

        new_res += gr[v][num] + gr[num][to];
    }

    for(int i : vert) {
        ve[i] = false;
    }

    res = min(res, new_res);
}

int this_res = 0;

void rec(int id) {
    //if (this_res >= res) return;
    if (id * 2 >= k) {
        check();
        return;
    }

    for(int i = 0;i < n;i++) {
        vert[id] = i;
        int pr = vert[id - 1];
        int mid = dp[pr][i][0];
        this_res += gr[pr][mid] + gr[mid][i];

        rec(id + 1);
        this_res -= gr[pr][mid] + gr[mid][i];
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> gr[i][j];
            if (i == j) gr[i][j] = inf;
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            vector<int> temp;
            for(int q = 0;q < n;q++)
                temp.emplace_back(q);

            sort(all(temp), [i, j](int v1, int v2) {
                return gr[i][v1] + gr[v1][j] < gr[i][v2] + gr[v2][j];
            });

            for(int q = 0;q < n;q++)
                dp[i][j][q] = temp[q];
        }
    }
    vert.resize(k / 2 + 1);

    rec(1);

    cout << res;
}