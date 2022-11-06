#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;
vector<int> num;
vector<int> ans;

void gen(int ind)
{
    if (num[ind] == 0)
    {
        if (ind)
            gen(ind - 1);
        while (num[ind] < v[ind].second)
        {
            num[ind]++;
            ans.push_back(ans.back() * v[ind].first);
            if (ind)
                gen(ind - 1);
        }
    }
    else
    {
        if (ind)
            gen(ind - 1);
        while (num[ind])
        {
            num[ind]--;
            ans.push_back(ans.back() / v[ind].first);
            if (ind)
                gen(ind - 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        v.clear();
        ans.clear();
        num.clear();
        int n;
        cin >> n;
        int temp = n;
        for (int i = 2; temp > 1 && i * i <= n; i++)
        {
            if (temp % i == 0)
            {
                int cnt = 0;
                while (temp % i == 0)
                {
                    temp /= i;
                    cnt++;
                }
                v.push_back(make_pair(i, cnt));
            }
        }
        if (temp > 1)
            v.push_back(make_pair(temp, 1));
        num.resize((int) v.size(), 0);
        ans.clear();
        ans.push_back(1);
        gen((int) v.size() - 1);
        int ops = 0;
        if ((int) ans.size() > 2 && __gcd(ans[1], ans.back()) == 1)
        {
            int save = ans.back();
            ans.pop_back();
            int save2 = ans.back();
            ans.pop_back();
            ans.push_back(save);
            ans.push_back(save2);
            for (int i = 1; i < (int) ans.size() - 1; i++)
            {
                if (__gcd(ans[i], ans[i + 1]) == 1)
                    ops++;
            }
            if (__gcd(ans[1], ans.back()) == 1)
                ops++;
        }
        for (int i = 1; i < (int) ans.size(); i++)
        {
            cout << ans[i] << " \n"[i == (int) ans.size() - 1];
        }
        cout << ops << "\n";
    }
    return 0;
}