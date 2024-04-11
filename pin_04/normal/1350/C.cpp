#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Nmax = 2e5 + 5;

set <int> s;

vector <int> del;

int a[Nmax];
int p[Nmax];
int cnt[Nmax][3];
int n,ans;

void era()
{
    for (int i = 2; i * i<= 2e5; i++)
    {
        if (p[i]) continue;
        for (int j = i * i; j <= 2e5; j += i)
        {
            if (p[j]) continue;
            p[j] = i;
        }
    }
    for (int i = 2; i <= 2e5; i++)
    {
        if (!p[i])
        {
            p[i] = i;
            s.insert(i);
        }
    }
}

signed main()
{
    //freopen("file.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < Nmax; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cnt[i][j] = 1e9;
        }
    }
    era();
    for (int i = 1; i <= n; i++)
    {
        for (auto itr = s.begin(); itr != s.end(); itr++)
        {
            int j = *itr;
            int res = 0;
            while (a[i] % j == 0)
            {
                res++;
                a[i] /= j;
            }
            cnt[j][2] = res;
            sort(cnt[j], cnt[j] + 3);
            if (cnt[j][0] == 0 && cnt[j][1] == 0)
            {
                del.push_back(j);
            }
        }
        for (int x : del) s.erase(x);
        del.clear();
    }
    ans = 1;
    for (int i = 2; i < Nmax; i++)
    {
        if (p[i] != i) continue;
        for (int j = 1; j <= cnt[i][1]; j++)
        {
            ans *= i;
        }
    }
    cout << ans;
    return 0;
}