#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    map<int, vector<int>> freq;
    while (t--)
    {
        freq.clear();
        int n;
        cin >> n;
        int biggest = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            biggest = max(biggest, a[i]);
            freq[a[i]].push_back(i);
        }
        if ((int) freq[biggest].size() >= 3)
        {
            cout << "YES\n";
            cout << freq[biggest][1] << " 1 " << n - 1 - freq[biggest][1] << "\n";
            continue;
        }
        int left = freq[biggest][0];
        int right = freq[biggest].back();
        int cnt = (int) freq[biggest].size();
        freq.erase(biggest);
        int x, y, z;
        x = y = z = -1;
        while (!freq.empty())
        {
            auto it = freq.end();
            it--;
            vector<int> v = it->second;
            freq.erase(it->first);
            if ((int) v.size() >= 3 && v[0] < left && v.back() > right)
            {
                int interval = cnt;
                int near = -1;
                for (int x : v)
                {
                    if (x == v[0] || x == v.back())
                        continue;
                    if (x == left - 1 || x == right + 1)
                        near = x;
                    if (x >= left && x <= right)
                    {
                        interval++;
                        near = x;
                    }
                }
                if (interval == right - left + 1 && near != -1)
                {
                    x = left;
                    y = right - left + 1;
                    if (near == left - 1)
                    {
                        x--;
                        y++;
                    }
                    else if (near == right + 1)
                    {
                        y++;
                    }
                    z = n - x - y;
                    break;
                }
            }
            cnt += (int) v.size();
            left = min(left, v[0]);
            right = max(right, v.back());
        }
        if (x == -1)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            cout << x << " " << y << " " << z << "\n";
        }
    }
    return 0;
}