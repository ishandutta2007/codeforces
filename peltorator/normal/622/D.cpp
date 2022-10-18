#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
     
using namespace std;
     
typedef long long ll;
typedef long double ld;
     
const ll MOD = 1000000007;
const int N = 1000001;
const int MAXN = N;

int d[N], used[N];

int best = 1e9;
vector<vector<int> > ans;
vector<int> e;
int n;

void f(int k)
{
    if (k == n + 1)
    {
        int cur = 0;
        for (int i = 1; i <= n; i++)
            cur += (n - i) * abs(d[i] - (n - i));
        if (cur < best)
        {
            ans.clear();
            ans.push_back(e);
            best = cur;
            for (int i = 1; i <= 2 * n; i++)
                ans[0][i] = used[i];
        }
        else if (cur == best)
        {
            ans.push_back(e);
            for (int i = 1; i <= 2 * n; i++)
                ans[ans.size() - 1][i] = used[i];
        }
        return;
    }
    for (int i = 1; i <= 2 * n; i++)
        if (!used[i])
        {
            for (int j = i + 1; j <= 2 * n; j++)
                if (!used[j])
                {
                    used[i] = used[j] = k;
                    d[k] = j - i;
                    f(k + 1);
                    used[i] = used[j] = 0;
                }
        }
}

int a[N];


int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /*n = 3;
    e.resize(2 * n + 1);
    f(1);
    for (int j = 0; j < ans.size(); j++)
    {
        for (int i = 1; i <= 2 * n; i++)
        cout << ans[j][i] << " ";
        cout << endl;
    }*/
    int n;
    cin >> n;
    for (int i = 1; i <= n; i += 2)
        cout << i << " ";
    int x = n;
    if (x % 2 == 0)
        x--;
    if (n % 2)
        x -= 2;
    for (int i = x; i > 0; i -= 2)
        cout << i << " ";
    for (int i = 2; i <= n; i += 2)
        cout << i << " ";
    x = n;
    if (x % 2)
        x--;
    if (n % 2 == 0)
        x -= 2;
    for (int i = x; i >= 1; i -= 2)
        cout << i << " ";
    cout << n;
    return 0;
}