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

const int maxn = 2e5 + 10,
      maxk = 10;
bool bad[maxk][maxk][maxk][maxk];
vector<pii> adj[maxn];
vector<char> jda[maxn][maxk];
char btarr[maxk];
int n, m, k;

int go(int pos = 0) {
    if (pos == k) {
//        for (int i = 0; i < pos; i++)
//            cout << int(btarr[i]) << ' ';
//        cout << endl;
        return 1;
    }
    int ans = 0;
    for (int i = 0; i <= pos; i++) {
        bool valid = true;
        btarr[pos] = i;
        for (int prv = 0; prv <= pos; prv++)
            if (bad[pos][i][prv][btarr[prv]]) {
                valid = false;
                break;
            }
        if (valid)
            ans += go(pos + 1);
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int fi, se, th;
        cin >> fi >> se >> th;
        adj[fi - 1].PB(MP(th, se - 1));
    }
    for (int i = 0; i < n; i++) {
        sort(all(adj[i]));
        for (int j = 0; j < sz(adj[i]); j++) {
            int u = adj[i][j].R;
            jda[u][sz(adj[i]) - 1].PB(j);
        }
    }
    for (int u = 0; u < n; u++) {
        for (int i = 0; i < k; i++) {
            sort(all(jda[u][i]));
//            cout << u << ' ' << i << ":\n\t";
//            for (auto num : jda[u][i])
//                cout << int(num) << ' ';
//            cout << endl;
            for (int j = 1; j < sz(jda[u][i]); j++)
                if (jda[u][i][j] == jda[u][i][j - 1])
                    bad[i][jda[u][i][j]][i][jda[u][i][j]] = true;
            for (auto iv : jda[u][i])
                for (int j = 0; j < i; j++)
                    for (auto jv : jda[u][j]) {
                        bad[i][iv][j][jv] = true;
                        bad[j][jv][i][iv] = true;
                    }
        }
    }
    cout << go() << endl;
	return 0;
}