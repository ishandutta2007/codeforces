#include <bits/stdc++.h>

using namespace std;

const int MAXK = 15;
const int MAXN = 5000;
int n[MAXK];
vector<int> a[MAXK];
unordered_map<long long, int> m;
bool dp[1 << MAXK];
int result[MAXK][MAXN];
long long s[MAXK];
pair<int, int> where[1 << MAXK];

int main()
{
    int k;
    cin >> k;
    long long sum = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> n[i];
        a[i] = vector<int>(n[i]);
        for (int j = 0; j < n[i]; j++)
        {
            cin >> a[i][j];
            m[a[i][j]] = i;
            sum += a[i][j];
            s[i] += a[i][j];
        }
    }
    if (sum % k != 0)
    {
        cout << "No" << endl;
    }
    else
    {
        long long target = sum / k;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n[i]; j++)
            {
                int ans = 1 << i;
                long long next = target - (s[i] - a[i][j]);
                if (m.find(next) != m.end())
                {
                    int comp = m[next];
                    while (comp != -1 && (ans & (1 << comp)) == 0)
                    {
                        ans |= 1 << comp;
                        next = target - (s[comp] - next);
                        if (m.find(next) == m.end())
                            comp = -1;
                        else
                            comp = m[next];
                    }
                    if (comp != i || next != a[i][j])
                        ans = -1;
                }
                else
                {
                    ans = -1;
                }
                result[i][j] = ans;
            }
        }
        dp[0] = true;
        for (int i = 1; i < (1 << k); i++)
        {
            int lsb = i & -i;
            int comp = __builtin_ctz(lsb);
            for (int j = 0; j < n[comp]; j++)
            {
                if (result[comp][j] != -1 && (result[comp][j] & i) == result[comp][j])
                {
                    if (dp[i ^ result[comp][j]])
                    {
                        dp[i] = true;
                        where[i] = {comp, j};
                    }
                }
            }
        }
        if (dp[(1 << k) - 1])
        {
            cout << "Yes" << endl;
            int bit = (1 << k) - 1;
            pair<int, int> ans[MAXK];
            while (bit > 0)
            {
                pair<int, int> pr = where[bit];
                int next = (int) (target - (s[pr.first] - a[pr.first][pr.second]));
                int comp = pr.first;
                while (m[next] != pr.first)
                {
                    bit ^= (1 << m[next]);
                    ans[m[next]] = {next, comp};
                    comp = m[next];
                    next = (int) (target - (s[comp] - next));
                }
                ans[pr.first] = {next, comp};
                bit ^= (1 << pr.first);
            }
            for (int i = 0; i < k; i++)
            {
                cout << ans[i].first << " " << ans[i].second + 1 << endl;
            }
        }
        else
            cout << "No" << endl;
    }
    return 0;
}