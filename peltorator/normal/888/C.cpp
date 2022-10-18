#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 300001;

vector<int> q;

int main()
{
   //freopen("in.txt", "r", stdin);
 //   cout.precision(100);
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int ans = 1e9;
    for (char c = 'a'; c <= 'z'; c++)
    {
        int cur = 0, t = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
                cur = 0;
            else
                cur++;
            t = max(t, cur);
        }
        ans = min(ans, t);
    }
    cout << ans + 1;
    return 0;
}