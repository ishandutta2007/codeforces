#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define sz(a) (int)(a).size()

const int N = 5001;
const int F = 26;

int cnt[N];
int a[F][F][N];

int solve()
{
    ios::sync_with_stdio(0);
    string s;
    if (!(cin >> s))
        return 1;
    int n = s.size();
    for (int i = 0; i < N; i++)
        cnt[i] = 0;
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;
    s += s;
    for (int k = 0; k < N; k++)
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                a[i][j][k] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[s[i] - 'a'][s[j + i] - 'a'][j]++;
    ll ans = 0;
    for (int i = 0; i < 26; i++)
    {
        int kek = 0;
        for (int j = 0; j < n; j++)
        {
            int ex = 0;
            for (int k = 0; k < 26; k++)
            {
                if (a[i][k][j] == 1)
                    ex++;
            }
            kek = max(kek,ex);
        }
        ans += kek;
    }
    cout << (ld)ans / (ld)n << endl;
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