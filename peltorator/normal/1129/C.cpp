#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>
#include <random>
#include <iomanip>

#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

const int N = 3005;
const ll MOD = 1e9 + 7;

ll dp[N][N];

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}


int solve()
{
  /*  int xx = 3000;
    cout << xx << endl;
    for (int i = 0; i < xx; i++)
        cout << "1\n";
    return 1;*/
    int n;
    if (!(cin >> n))
        return 1;
    string s = "";
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        s.push_back(c);
    }
    vector<string> v = {"0", "1", "00", "01", "10", "11", "000", "001", "010", "011", "100", "101", "110", "111"};
    for (int i = 0; i < (1 << 4); i++)
    {
        string t = "";
        for (int j = 0; j < 4; j++)
            if ((i >> j) & 1)
                t.push_back('0');
            else
                t.push_back('1');
        if (t != "0011" && t != "0101" && t != "1110" && t != "1111")
            v.push_back(t);
    }
    vector<vector<int> > z(n, vector<int>(v.size(), 0));
    for (int i = 0; i < v.size(); i++)
    {
        string t = v[i] + s;
        vector<int> zz = z_function(t);
        for (int j = 0; j < s.size(); j++)
            z[j][i] = zz[j + v[i].size()];
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = 0;
    for (int i = 0; i < N; i++)
        dp[i][i] = 1;
    for (int l = 1; l <= n; l++)
        for (int i = 0; i + l <= n; i++)
        {
            int j = i + l;
            for (int k = 0; k < v.size(); k++)
            {
                if (l >= v[k].size())
                {
                    /*bool ok = 1;
                    for (int k = 0; ok && k < t.size(); k++)
                        if (t[k] != s[k + i])
                            ok = 0;*/
                    if (z[i][k] >= v[k].size())
                        dp[j][i] += dp[j][i + v[k].size()];
                }
            }
            dp[j][i] %= MOD;
        }
    vector<int> mxz(n, 0);
    for (int i = 0; i < n; i++)
    {
        string t = "";
        for (int j = i; j < n; j++)
            t.push_back(s[j]);
        vector<int> z = z_function(t);
        for (int j = 1; j < z.size(); j++)
            mxz[i + j] = max(mxz[i + j], z[j]);
    }
    ll cur = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (mxz[j] < i - j + 1)
                cur += dp[i + 1][j];
        }
        cur %= MOD;
        cout << cur << '\n';
    }
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cout << "__________________________\n";
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}