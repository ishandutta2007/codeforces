#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif // LOCAL
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define pb push_back
#define sz(c) ((int)(c).size())

vector<int> p_div (int n)
{
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
        ans.push_back(n);
    return ans;
}

int max_div (int n)
{
    int ans = 1;
    for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
        ans = i;

    return ans;
}

void add (int &a, int b, int mod)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
void sub (int &a, int b, int mod)
{
    a -= b;
    if (a < 0)
        a += mod;
}
int mult (int a, int b, int mod)
{
    return int((ll)a * b % mod);
}
int powmod (int a, int pw, int mod)
{
    int ans = 1;
    while (pw)
    {
        if (pw & 1)
            ans = mult(ans, a, mod);
        a = mult(a, a, mod);
        pw >>= 1;
    }
    return ans;
}

int find_root (int p)
{
    vector<int> ps = p_div(p - 1);
    for (int g = 2; ; g++)
    {
        bool ok = true;
        for (int x : ps) if (powmod(g, (p - 1) / x, p) == 1)
        {
            ok = false;
            break;
        }

        if (ok)
            return g;
    }

    assert(false);
    return -1;
}

int get_hash (const string &s, int p, int r)
{
    int ans = 0, cur_pw = 1;
    for (char ch : s)
    {
        add(ans, mult(cur_pw, ch, p), p);
        cur_pw = mult(cur_pw, r, p);
    }
    return ans;
}

#ifdef LOCAL
#define TEST
#endif // LOCAL

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
#ifndef TEST
    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;
    assert(sz(a) == n && sz(b) == n);
#else
    char tmp;
    cin >> tmp;

    const int n = int(1e5);
    const int m = int(1e5);
    const int let = 26;

    string a, b;
    mt19937 rng(736);
    for (int i = 0; i < n; i++)
    {
        a += char(rng() % let + 'a');
        b += char(rng() % let + 'b');
    }
#endif

    vector<int> v(n);
    const int K = 200;

    for (int p = m; ; p++) if (max_div(p) == 1)
    {
        const int d = max_div(p - 1);
        if (d < K)
            continue;

        const int g = find_root(p);
        vector<int> pws(p - 1);
        pws[0] = 1;
        for (int i = 1; i < p - 1; i++)
            pws[i] = mult(pws[i - 1], g, p);

        vector<char> was_val(p);

        for (int xanum = 0; xanum < p - 1; xanum += d)
        {
            const int root = pws[xanum];

            for (int i = 0; i < n; i++)
            {
                v[i] = int(a[i] - b[i]) % p;
                if (v[i] < 0)
                    v[i] += p;
            }

            for (int i = n - 1; i >= 0; i--)
            {
                if (i >= d)
                {
                    add(v[i - d], mult(v[i], root, p), p);
                    v[i] = 0;
                }
            }

            for (int i = xanum / d; i < p - 1; i += (p - 1) / d)
            {
                const int r = pws[i];
                was_val[r] = 1;
                assert(powmod(r, d, p) == root);

                if (r == 1 || r == p - 1)
                    continue;

                int cur_pw = 1, sum = 0;
                for (int j = 0; j < min(n, d); j++)
                {
                    add(sum, mult(cur_pw, v[j], p), p);
                    cur_pw = mult(cur_pw, r, p);
                }

                if (sum == 0)
                {
                    assert(get_hash(a, p, r) == get_hash(b, p, r));
                    assert(m <= p && p <= int(1e9));
                    assert(2 <= r && r <= p - 2);

                    cout << p << ' ' << r << endl;
                    return;
                }
            }
        }

        assert(was_val[0] == 0);
        assert(count(was_val.begin(), was_val.end(), 1) == p - 1);
    }

    assert(false);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}