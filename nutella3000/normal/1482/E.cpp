#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(time(0));

//        //\\      ||||||  ||||          //\\        ||||||
//       //  \\       ||    ||  ||       //  \\       ||   ||
//      //    \\      ||    ||   ||     //    \\      ||   ||
//     //------\\     ||    ||   ||    //------\\     ||||||
//    //        \\    ||    ||   ||   //        \\    ||  \\
//   //          \\ ||||||  |||||    //          \\   ||   \\

#define AIDAR ASSADULIN

#define int long long
#define mp make_pair
#define all(a) a.begin(), a.end()
#define pii pair<int, int>
#define fi first
#define se second
#define ld long double
#define size(a) (int)(a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)

const int inf = 1e18 + 2;
const int max_n = 601;

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}


signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(15);

    #ifdef technocum
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> gr(n, vector<int>(n, inf)), d(n, vector<int>(n, inf));

    for(int i = 0;i < m;i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        --v1; --v2;
        d[v1][v2] = w;
        d[v2][v1] = w;
        gr[v1][v2] = w;
        gr[v2][v1] = w;
    }

    for(int i = 0;i < n;i++)
        d[i][i] = 0;

    for(int k = 0;k < n;k++) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                chkmin(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    vector<vector<int>> l(n, vector<int>(n));

    int q;
    cin >> q;
    for(int i = 0;i < q;i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        --v1, --v2;
        l[v1][v2] = l[v2][v1] = w;
    }

    vector<vector<int>> t(n, vector<int>(n, -1));

    for(int a = 0;a < n;a++) {
        for(int v = 0;v < n;v++) {
            for(int b = 0;b < n;b++)
                chkmax(t[a][v], l[a][b] - d[v][b]);
        }
    }


    int res = 0;
    for(int v = 0;v < n;v++) {
        for(int u = 0;u < n;u++) {
            for(int a = 0;a < n;a++) {
                if (d[a][v] + gr[v][u] <= t[a][u]) {
                    res++;
                    break;
                }
            }
        }
    }
    cout << res / 2 << endl;
}