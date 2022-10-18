#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define sz(a) (int)(a).size()

const int N = 200001;
const int T = 2;

vector<pair<int, int> > q;
int a[N];

int dp[T][N];
const int R = 2000001;
int t[R];

void tu(int v, int l, int r, int q, int val)
{
    if (r <= l || q >= r || q < l)
        return;
    t[v] = max(t[v], val);
    if (l + 1 == r)
        return;
    int mid = (r + l) / 2;
    tu(2 * v, l, mid, q, val);
    tu(2 * v + 1, mid, r, q, val);
}

int tf(int v, int l, int r, int ql, int qr)
{
    if (r <= l || ql >= r || l >= qr)
        return 0;
    if (ql <= l && r <= qr)
        return t[v];
    int mid = (r + l) /2;
    return max(tf(2 *v , l, mid, ql, qr), tf(2 * v + 1, mid, r, ql, qr));
}

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
        return 1;
    int m;
    cin >> m;
    q.clear();
    for (int i = 0; i < n; i++)
    {
        int l,r ;
        cin >> l >>r;
        q.push_back({l, -1});
        q.push_back({r + 1, 1});
    }
    sort(q.begin(), q.end());
    int it = 0;
    for (int i = 0; i < N; i++)
        a[i]= 0;
    int kek = 0;
    for (int i = 1; i <= m; i++)
    {
        while (it < q.size() && q[it].first <= i)
            kek -= q[it].second, it++;
        a[i] = kek;
        //cout << kek << endl;
    }
    bool tt = 1, q =1;
    for (int i = 1; i < m; i++)
        if (a[i + 1] < a[i])
            tt = 0;
        else if (a[i + 1] > a[i])
            q = 0;
    if (tt || q)
    {
        cout << m << endl;
        return 0;
    }
    for (int i = 0; i < N; i++)
        dp[0][i] = dp[1][i] = 0;
    for (int ii = 0; ii < 2; ii++)
    {
        for (int i = 0; i < R; i++)
            t[i] = 0;
        dp[ii][0] = 0;
        for (int i = 1; i <= m; i++)
        {
            dp[ii][i] = tf(1, 0, n + 1, 0, a[i] + 1) + 1;
            tu(1, 0, n + 1, a[i], dp[ii][i]);
           // dp[ii][i] = max(dp[ii][i], dp[ii][i - 1]);
        }
        for (int i = 1; m - i + 1 > i; i++)
            swap(a[i], a[m - i + 1]);
    }
  //  cout << dp[1][1] << endl;
    for (int i = 1; m - i + 1 > i; i++)
        swap(dp[1][i], dp[1][m - i + 1]);
   // cout << dp[1][m] << endl;
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = max(ans, dp[0][i] + dp[1][i] - 1);
    cout << ans << endl;
    return 0;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    for (int i = 1;; i++)
    {
        #ifndef ONLINE_JUDGE
            cerr << "Test #" << i << ":\n";
        #endif // ONLINE_JUDGE
        if (solve())
            break;
        #ifndef ONLINE_JUDGE
            cerr << "____________________________\n";
        #endif // ONLINE_JUDGE
    }
    #ifndef ONLINE_JUDGE
        cerr << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif // ONLINE_JUDGE
    return 0;
}