#include <bits/stdc++.h>

using namespace std;

const int BASE = 3;
const int MODS[3] = {(int) 1E9 + 7, (int) 1E9 + 9, (int)1E9 + 21};
const int MAXN = 2E5;
int pref[3][26][MAXN + 1];
int inv[3][MAXN + 1];
vector<pair<int, int>> chars[MAXN + 1];

int modpow(int b, int e, int mod)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) ((long long) ans * b % mod);
        b = (int) ((long long) b * b % mod);
        e >>= 1;
    }
    return ans;
}

int modinv(int x, int mod)
{
    return modpow(x, mod - 2, mod);
}

void add(int &a, int b, int mod)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

int getInterval(int hsh[MAXN + 1], int l, int r, int mod, int inverse[MAXN + 1])
{
    int ans = hsh[r];
    add(ans, mod - hsh[l - 1], mod);
    ans = (int) ((long long) ans * inverse[l - 1] % mod);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 3; i++)
    {
        inv[i][0] = 1;
        inv[i][1] = modinv(BASE, MODS[i]);
        for (int j = 2; j <= MAXN; j++)
            inv[i][j] = (int) ((long long) inv[i][j - 1] * inv[i][1] % MODS[i]);
    }
    int n, m;
    string s;
    cin >> n >> m >> s;
    s = " " + s;
    for (int i = 0; i < 3; i++)
    {
        int p = 1;
        for (int j = 1; j <= n; j++)
        {
            int key = s[j] - 'a';
            for (int k = 0; k < 26; k++)
                pref[i][k][j] = pref[i][k][j - 1];
            add(pref[i][key][j], p, MODS[i]);
            p = (int) ((long long) p * BASE % MODS[i]);
        }
    }
    for (int i = 0; i < 26; i++)
    {
        int ind = 0;
        for (int j = n; j >= 1; j--)
        {
            if (s[j] - 'a' == i)
                ind = j;
            if (ind)
                chars[j].push_back(make_pair(ind, i));
        }
    }
    for (int i = 1; i <= n; i++)
        sort(chars[i].begin(), chars[i].end());
    while (m--)
    {
        int x, y, len;
        cin >> x >> y >> len;
        bool ans = true;
        int cur = 0;
        while (cur < (int) chars[x].size() && cur < (int) chars[y].size() && chars[x][cur].first < x + len)
        {
            if (chars[x][cur].first - x != chars[y][cur].first - y)
            {
                ans = false;
                break;
            }
            int c1 = chars[x][cur].second;
            int c2 = chars[y][cur].second;
            for (int i = 0; i < 3; i++)
            {
                int mod = MODS[i];
                if (getInterval(pref[i][c1], x, x + len - 1, mod, inv[i]) != getInterval(pref[i][c2], y, y + len - 1, mod, inv[i]))
                {
                    ans = false;
                    break;
                }
            }
            if (!ans)
                break;
            cur++;
        }
        if (cur < (int) chars[y].size() && chars[y][cur].first < y + len)
            ans = false;
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}