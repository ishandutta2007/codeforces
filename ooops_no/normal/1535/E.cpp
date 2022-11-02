#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3e5 + 10;
vector<int> g[N], sum(N), col(N);
int po[20][N];
vector<int> par(N);
vector<int> a(N), c(N);

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q >> a[0] >> c[0];
    int now = 0;
    while(q--){
        int t;
        cin >> t;
        now++;
        if (t == 1){
            int p;
            cin >> p >> a[now] >> c[now];
            po[0][now] = p;
            for (int i = 1; i < 20; i++){
                po[i][now] = po[i - 1][po[i - 1][now]];
            }
        }
        else{
            int u, w;
            cin >> u >> w;
            int cnt = 0, sum = 0;
            while(w && a[u]){
                int v = u;
                for (int i = 19; i >= 0; i--){
                    if (a[po[i][v]]){
                        v = po[i][v];
                    }
                }
                if (w < a[v]){
                    a[v] -= w;
                    cnt += w;
                    sum += w * c[v];
                    w = 0;
                }
                else{
                    cnt += a[v];
                    w -= a[v];
                    sum += a[v] * c[v];
                    a[v] = 0;
                }
            }
            cout << cnt << ' ' << sum << endl;
        }
    }
    return 0;
}