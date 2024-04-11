#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> pos;
    vector<int> neg;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        if (c >= 0)
        {
            sum += c;
            pos.push_back(c);
        }
        else
            neg.push_back(c);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    long long cur = 0;
    int level = 0;
    vector<vector<int>> blocks;
    int ptr = 0;
    while (ptr < (int) neg.size())
    {
        blocks.push_back(vector<int>());
        for (int i = 0; i < k + 1; i++)
        {
            if (ptr + i >= (int) neg.size())
                break;
            cur += (long long) level * neg[ptr + i];
            blocks.back().push_back(neg[ptr + i]);
        }
        level++;
        ptr += k + 1;
    }
    for (int i = 0; i < (int) pos.size(); i++)
    {
        cur += (long long) (level + i) * pos[i];
    }
    long long ans = cur;
    while (!blocks.empty())
    {
        if ((int) blocks.back().size() == 1)
        {
            sum += blocks.back()[0];
            blocks.pop_back();
        }
        else
        {
            sum += blocks.back().back();
            cur += sum;
            blocks.back().pop_back();
            ans = max(ans, cur);
        }
    }
    cout << ans << "\n";
    return 0;
}