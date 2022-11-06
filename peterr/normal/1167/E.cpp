#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
int arr[MAXN];
int sufMin[MAXN];
int preMax[MAXN];
int first[MAXN + 1];
int last[MAXN + 1];

bool isSorted(int left, int right, int n)
{
    int cur = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= left && arr[i] <= right)
            continue;
        if (arr[i] < cur)
            return false;
        cur = arr[i];
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    fill(first + 1, first + x + 1, n);
    fill(last + 1, last + x + 1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        last[arr[i]] = i;
        if (first[arr[i]] == n)
            first[arr[i]] = i;
        if (i == 0)
            preMax[i] = arr[i];
        else
            preMax[i] = max(arr[i], preMax[i - 1]);
    }
    sufMin[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        sufMin[i] = min(arr[i], sufMin[i + 1]);
    }
    int left = 1;
    int right = 0;
    for (int jump = x / 2 + 1; jump > 0; jump /= 2)
    {
        while (right + jump <= x && !isSorted(left, right + jump, n))
            right += jump;
    }
    right++;
    long long ans = 0;
    while (left <= x)
    {
        ans += x - right + 1;
        if (first[left] != n && sufMin[first[left]] != left)
            break;
        if (last[left] > 0)
        {
            right = max(right, preMax[last[left] - 1]);
        }
        left++;
        right = max(right, left);
    }
    cout << ans << endl;
    return 0;
}