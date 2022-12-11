#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> ans1;
vector<char> ans2;
vector<int> ans3;

vector<int> a;

int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

void get(int x, int a)
{
    int cur = x;
    int t = 1;
    int cnt = 1;
    while (t < a)
    {
        ++cnt;
        ans1.push_back(cur);
        ans2.push_back('+');
        ans3.push_back(cur);
        cur += cur;
        t *= 2;
    }
    cur = 0;
    for (int i = 0; i < cnt; ++i)
    {
        if (a & (1ll << i))
        {
            ans1.push_back(cur);
            ans2.push_back('+');
            ans3.push_back(((1ll << i) * x));
            cur += ((1ll << i) * x);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); srand(clock());
    int n;
    cin >> n;
    ans1.push_back(n);
    ans2.push_back('^');
    ans3.push_back(n);
    a.push_back(n);
    vector<int> t;
    t.push_back(n);
    for (int i = 2; i <= 64; ++i)
    {
        a.push_back(i * n);
        ans1.push_back(n);
        ans2.push_back('+');
        ans3.push_back((i - 1) * n);
        t.push_back(i * n);
    }
    for (int i = 0; i < 30; ++i)
    {
        int cur = (rand() * 25521 + rand()) % 1674137;
        t.push_back(cur * n);
        get(n, cur);
    }
    for (int i = 1; i <= t.size(); ++i)
    {
        for (int j = i + 1; j <= t.size(); ++j)
        {
            int ii = t[i];
            int jj = t[j];
            ans1.push_back((ii));
            ans2.push_back('^');
            ans3.push_back((jj));
            a.push_back((ii) ^ (jj));
        }
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = i + 1; j < a.size(); ++j)
        {
            int x = a[i];
            int y = a[j];
            int p, q;
            int g = gcd(x, y, p, q);
            if (g == 1) {
                p = (p % y + y) % y;
                if ((p * x) % 2 == 1)
                {
                    get(x, p);
                    get(y, (x * p - 1 + y) / y - 1);
                    ans1.push_back((x * p));
                    ans2.push_back('^');
                    ans3.push_back((x * p - 1));
                    cout << ans1.size() << endl;
                    for (int i = 0; i < ans1.size(); ++i)
                    {
                        cout << ans1[i] << " " << ans2[i] << " " << ans3[i] << endl;
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}