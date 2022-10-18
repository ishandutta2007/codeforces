#include <bits\stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef vector<int> Vint;

char str[1 << 20];
const int let = 26;

void work_same(string s)
{
    int n = (int)s.size();
    int ans = 0;
    s += "-";

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (s[0] != ch)
            ans++;

        for (int i = 0; i < n; i++)
        if (s[i + 1] != ch)
            ans++;
    }

    printf("%d\n", ans);
    return;
}

void solve(int n)
{
    string s, t;
    scanf(" %s", str);
    s = string(str);
    scanf(" %s", str);
    t = string(str);

    if (t == s)
    {
        work_same(t);
        return;
    }

    int l = 0;
    int r = n - 1;

    while (s[l] == t[l])
        l++;
    while (s[r] == t[r])
        r--;

    assert(0 <= l && l <= r && r < n);

    int ok = 0;
    for (int tt = 0; tt < 2; tt++)
    {
        bool cur = true;
        for (int j = l; j < r; j++)
        {
            if (tt == 0)
                cur &= (s[j] == t[j + 1]);
            else
                cur &= (s[j + 1] == t[j]);
        }

        if (cur)
            ok++;
    }

    printf("%d\n", ok);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int n;
    while (cin >> n)
        solve(n);
}