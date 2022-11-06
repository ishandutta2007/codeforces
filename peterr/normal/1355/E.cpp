#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int h[MAXN];

long long getCost(int a, int r, int m, long long bal, long long over, long long under)
{
    long long temp = 0;
    if (over == under)
    {
        temp = over * m;
    }
    else if (over > under)
    {
        temp = r * bal + m * under;
    }
    else
    {
        temp = a * bal + m * over;
    }
    return temp;
}

long long solve(int n, int a, int r, int m, int tar)
{
    long long ans = 2E18;
    if (tar < 0)
        return ans;
    bool dontmove = m >= a + r;
    long long over, under;
    over = under = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[i] > tar)
            over += h[i] - tar;
        else
            under += tar - h[i];
    }
    if (dontmove)
        ans = min(ans, over * r + under * a);
    else
        ans = getCost(a, r, m, abs(over - under), over, under);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, r, m;
    cin >> n >> a >> r >> m;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        sum += h[i];
    }
    sort(h, h + n);
    long long over, under;
    over = under = 0;
    for (int i = 1; i < n; i++)
        over += h[i] - h[0];
    long long ans = 2E18;
    bool dontmove = m >= a + r;
    for (int i = 0; i < n; i++)
    {
        long long temp = 0;
        long long bal = abs(over - under);
        if (dontmove)
            temp = r * over + a * under;
        else
            temp = getCost(a, r, m, bal, over, under);
        ans = min(temp, ans);
        if (i < n - 1)
        {
            int diff = h[i + 1] - h[i];
            under += (long long) (i + 1) * diff;
            over -= (long long) (n - i - 1) * diff;
        }
    }
    for (int i = -2; i <= 2; i++)
        ans = min(ans, solve(n, a, r, m, (int) (sum / n) + i));
    cout << ans << "\n";
    return 0;
}