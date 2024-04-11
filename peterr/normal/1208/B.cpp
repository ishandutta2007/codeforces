#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
int arr[MAXN];
unordered_set<int> visited;
unordered_map<int, int> lastOcc;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int right = n - 1;
    while (right >= 0)
    {
        if (visited.find(arr[right]) != visited.end())
        {
            break;
        }
        else
        {
            visited.insert(arr[right]);
            right--;
        }
    }
    if (right == -1)
    {
        cout << 0 << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            lastOcc[arr[i]] = i;
        }
        int ans = MAXN + 5;
        int left = 0;
        visited.clear();
        while (left < n)
        {
            ans = min(ans, right - left + 1);
            left++;
            if (left < n)
            {
                if (visited.find(arr[left - 1]) != visited.end())
                {
                    break;
                }
                visited.insert(arr[left - 1]);
                right = max(right, lastOcc[arr[left - 1]]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}