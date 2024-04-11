#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int arr[MAXN + 1];
int pref[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pref[i] = arr[i] + pref[i - 1];
    }
    int ans = -1;
    vector<pair<int, int>> ranges;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += arr[k];
            int countt = 0;
            vector<pair<int, int>> vec;
            vec.push_back({i, j});
            int leftBnd = j;
            int right = j + 1;
            while (right <= n)
            {
                for (int left = right - 1; left >= leftBnd; left--)
                {
                    if (pref[right] - pref[left] == sum)
                    {
                        countt++;
                        vec.push_back({left + 1, right});
                        leftBnd = right;
                        break;
                    }
                }
                right++;
            }
            if (countt > ans)
            {
                ans = countt;
                ranges = vec;
            }
        }
    }
    cout << ans + 1 << endl;
    for (pair<int, int> p : ranges)
        cout << p.first << " " << p.second << endl;
    return 0;
}