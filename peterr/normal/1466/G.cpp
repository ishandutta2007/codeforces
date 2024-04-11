#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 1E5;
int twopow[MAXN + 1];
int twoinv[MAXN + 1];
int pref[26][MAXN];

void kmp(const string s, vector<int> &dp)
{
    int n = (int) s.length();
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int j = dp[i - 1];
        while (j && s[i] != s[j])
            j = dp[j - 1];
        dp[i] = j;
        if (s[i] == s[j])
            dp[i]++;
    }
}

void continueKmp(const string &s, const string &base, vector<int> &baseKmp, vector<int> &dp)
{
    int n = (int) s.length();
    dp[0] = s[0] == base[0];
    for (int i = 1; i < n; i++)
    {
        int j = dp[i - 1];
        if (j == (int) base.length())
            j = baseKmp[j - 1];
        while (j && s[i] != base[j])
            j = baseKmp[j - 1];
        dp[i] = j;
        if (s[i] == base[j])
            dp[i]++;
    }
}

void add(int &x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int modpow(int b, int e)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) ((long long) ans * b % MOD);
        b = (int) ((long long) b * b % MOD);
        e >>= 1;
    }
    return ans;
}

int modinv(int x)
{
    return modpow(x, MOD - 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    twopow[0] = twoinv[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        twopow[i] = twopow[i - 1];
        add(twopow[i], twopow[i]);
        twoinv[i] = modinv(twopow[i]);
    }
    int n, q;
    string s0, t;
    cin >> n >> q >> s0 >> t;
    pref[t[0] - 'a'][0] = twopow[n];
    for (int i = 0; i < 26; i++)
    {
        for (int j = 1; j < n; j++)
        {
            pref[i][j] = pref[i][j - 1];
            if (t[j] - 'a' == i)
                add(pref[i][j], twopow[n - j]);
            //cout << "pref " << i << " " << j << " " << pref[i][j] << endl;
        }
    }
    string sRight = s0;
    int ptr = 1;
    while (ptr - 1 < (int) t.length() && (int) sRight.length() < 2000000)
    {
        sRight = sRight + t[ptr - 1] + sRight;
        ptr++;
    }
    string sLeft = sRight;
    reverse(sLeft.begin(), sLeft.end());
    vector<int> kmpRight(sRight.length());
    vector<int> kmpLeft(sLeft.length());
    kmp(sRight, kmpRight);
    kmp(sLeft, kmpLeft);
    while (q--)
    {
        int k;
        string w;
        cin >> k >> w;
        string wRev = w;
        reverse(wRev.begin(), wRev.end());
        vector<int> firstKmp(s0.length() + w.length() + 1);
        kmp(w + "#" + s0, firstKmp);
        int ans = 0;
        for (int i = (int) w.length() + 1; i < (int) firstKmp.size(); i++)
        {
            ans += firstKmp[i] == (int) w.length();
        }
        vector<int> dpRight(w.length());
        vector<int> dpLeft(w.length());
        continueKmp(w, sRight, kmpRight, dpRight);
        continueKmp(wRev, sLeft, kmpLeft, dpLeft);
        int matchRight = dpRight[w.length() - 1];
        int matchLeft = dpLeft[w.length() - 1];
        vector<int> cutPoints(w.length());
        while (1)
        {
            if (matchRight < (int) w.length())
                cutPoints[w.length() - 1 - matchRight]++;
            if (matchRight == 0)
                break;
            matchRight = kmpRight[matchRight - 1];
        }
        while (1)
        {
            if (matchLeft < (int) w.length())
                cutPoints[matchLeft]++;
            if (matchLeft == 0)
                break;
            matchLeft = kmpLeft[matchLeft - 1];
        }
        int len = (int) s0.length();
        for (int i = 0; i < min(ptr, k); i++)
        {
            add(ans, ans);
            for (int j = 0; j < (int) w.length(); j++)
            {
                assert(cutPoints[j] <= 2);
                if (cutPoints[j] < 2 || max(j, (int) w.length() - j - 1) > len)
                    continue;
                if (t[i] == w[j])
                    ans++;
                /*
                cout << "query " << w << endl;
                cout << "iter " << i << endl;
                cout << "good " << j << endl;
                */
            }
            len = 2 * len + 1;
        }
        if (k > ptr)
        {
            ans = (int) ((long long) ans * twopow[k - ptr] % MOD);
            for (int i = 0; i < (int) w.length(); i++)
            {
                if (cutPoints[i] < 2)
                    continue;
                int key = w[i] - 'a';
                int temp = pref[key][k - 1];
                add(temp, MOD - pref[key][ptr - 1]);
                temp = (int) ((long long) temp * twoinv[n - k + 1] % MOD);
                add(ans, temp);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}