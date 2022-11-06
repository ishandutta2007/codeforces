#include <bits/stdc++.h>

using namespace std;

const int MAXN = 52;
int pos[MAXN + 1];

void applyOp(vector<int> &v, vector<int> &d)
{
    int n = (int) v.size();
    vector<int> temp;
    int ptr = n - 1;
    for (int i = (int) d.size() - 1; i >= 0; i--)
    {
        int num = d[i];
        for (int j = ptr - num + 1; j <= ptr; j++)
        {
            temp.push_back(v[j]);
        }
        ptr -= num;
    }
    for (int i = 0; i < n; i++)
        v[i] = temp[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> ans;
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            pos[v[i]] = i;
        }
        int cur = 1;
        int l1, r1, l2, r2;
        l1 = r1 = -1;
        bool changed = false;
        while (cur <= n)
        {
            int ind = pos[cur];
            l2 = ind;
            while (cur + 1 <= n && pos[cur + 1] == ind + 1)
            {
                cur++;
                ind++;
            }
            r2 = ind;
            if (l2 < l1)
            {
                vector<int> d;
                if (l2 >= 1)
                    d.push_back(l2);
                d.push_back(r2 - l2 + 1);
                d.push_back(r1 - r2);
                if (r1 < n - 1)
                    d.push_back(n - r1 - 1);
                applyOp(v, d);
                ans.push_back(d);
                changed = true;
                break;
            }
            l1 = l2;
            r1 = r2;
            cur++;
        }
        if (!changed)
            break;
    }
    cout << (int) ans.size() << "\n";
    for (int i = 0; i < (int) ans.size(); i++)
    {
        cout << ans[i].size();
        for (int x : ans[i])
        {
            cout << " " << x;
        }
        cout << "\n";
    }
    return 0;
}