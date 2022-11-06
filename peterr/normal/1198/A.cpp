#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4E5;
int arr[MAXN];
pair<int, int> freq[MAXN];

int main()
{
    int n, disk, m;
    cin >> n >> disk;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        freq[index] = {arr[i], 1};
        while (i + 1 < n && arr[i + 1] == arr[i])
        {
            i++;
            freq[index].second++;
        }
        index++;
    }
    m = index;
    int K = 1;
    for (int jump = n / 2 + 1; jump > 0; jump /= 2)
    {
        while (K + jump <= n && ceil(log2(K + jump)) <= 8 * disk / n)
        {
            K += jump;
        }
    }
    if (K >= m)
    {
        cout << 0 << endl;
    }
    else
    {
        int left = 0;
        int right = K - 1;
        int same = 0;
        int maxSame = -1;
        for (int i = left; i <= right; i++)
        {
            same += freq[i].second;
        }
        maxSame = same;
        while (right + 1 < m)
        {
            right++;
            left++;
            same += freq[right].second;
            same -= freq[left - 1].second;
            maxSame = max(maxSame, same);
        }
        cout << n - maxSame << endl;
    }
    return 0;
}