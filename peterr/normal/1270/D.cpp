#include <bits/stdc++.h>

using namespace std;

pair<int, int> query(vector<int> &v)
{
    cout << "?";
    for (int i = 0; i < (int) v.size(); i++)
    {
        cout << " " << v[i];
    }
    cout << endl;
    cout.flush();
    pair<int, int> ans;
    cin >> ans.first >> ans.second;
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= k; i++)
        v.push_back(i);
    pair<int, int> pr = query(v);
    int x = pr.second;
    int xpos = pr.first;
    v[xpos - 1] = k + 1;
    pr = query(v);
    int y = pr.second;
    int ypos = pr.first;
    vector<bool> diff(k, false);
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        if (v[i] == ypos)
            continue;
        int temp = v[i];
        v[i] = xpos;
        pr = query(v);
        v[i] = temp;
        if (pr.second == y)
            cnt++;
    }
    if (x > y)
    {
        cout << "! " << k - cnt << endl;
    }
    else
    {
        cout << "! " << cnt + 1 << endl;
    }
    return 0;
}