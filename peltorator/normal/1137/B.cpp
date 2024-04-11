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

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int solve()
{
    string s;
    if (!(cin >> s))
        return 1;
    string t;
    cin >> t;
    vector<int> pre = prefix_function(t);
    int len = t.size() - pre[t.size() - 1];
    int s0 = 0, s1 = 0;
    int t0 = 0, t1 = 0;
    int z0 = 0, z1 = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '0')
            s0++;
        else
            s1++;
    for (int i = 0; i < t.size(); i++)
        if (t[i] == '0')
            t0++;
        else
            t1++;
    for (int i = 0; i < len; i++)
        if (t[i] == '0')
            z0++;
        else
            z1++;
    string ans = "";
    if (s0 >= t0 && s1 >= t1)
    {
        ans = t;
        s0 -= t0;
        s1 -= t1;
        while (true)
        {
            if (s0 < z0 || s1 < z1)
            {
                break;
            }
            for (int i = (int)t.size() - len; i < t.size(); i++)
                ans.push_back(t[i]);
            s0 -= z0;
            s1 -= z1;
        }
    }
    for (int i = 0; i < s0; i++)
        ans.push_back('0');
    for (int j = 0; j < s1; j++)
        ans.push_back('1');
    cout << ans << '\n';
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