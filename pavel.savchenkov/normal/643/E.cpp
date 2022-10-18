#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define sz(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()

const int N = (int)5e5 + 10;
const int K = 60;
typedef double T;
T dp[N][K];
int par[N];

void solve (int n)
{
    int curv = 2;
    memset(dp, 0, sizeof dp);
    for (int i = 1; i < K; i++)
        dp[1][i] = 1.0;
    par[1] = -1;

    for (int i = 0; i < n; i++)
    {
        int type, v;
        cin >> type >> v;
//        type = 1, v = i + 1;

        if (type == 1)
        {
            par[curv] = v;
            dp[curv][0] = 0.0;
            for (int i = 1; i < K; i++)
                dp[curv][i] = 1.0;

            assert(par[curv] == v);
            T old_val = dp[v][1];
            dp[v][1] *= (0.5 + 0.5 * dp[curv][0]);

            int cv = v;
            for (int i = 2; i < K; i++)
            {
                int u = par[cv];
                assert(u != 0);
                if (u == -1)
                    break;

                T nold = dp[u][i];
                dp[u][i] /= (0.5 + 0.5 * old_val);
                dp[u][i] *= (0.5 + 0.5 * dp[cv][i - 1]);
                old_val = nold;
                cv = u;
            }

            curv++;
        }
        else
        {
            T ans = 0;
            for (int i = 1; i < K; i++)
            {
                //cerr << dp[v][i] << ' ';
                ans += (1.0 - dp[v][i]);
            }
            //cerr << endl;
            printf("%.12f\n", (double)ans);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 5e5;
    while (cin >> n)
        solve(n);
}