#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];
vector<int> segs;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ptr = 1;
    while (ptr < n)
    {
        int start = ptr - 1;
        int dir = a[ptr] - a[ptr - 1];
        while (ptr + 1 < n && (long long) (a[ptr + 1] - a[ptr]) * dir > 0)
            ptr++;
        segs.push_back(ptr - start + 1);
        ptr++;
    }
    sort(segs.begin(), segs.end());
    int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] < a[i - 1] || a[i] < a[i + 1])
            continue;
        int len1 = 1;
        int len2 = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] > a[j + 1])
                break;
            len1++;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[j - 1])
                break;
            len2++;
        }
        if (len1 < len2)
            swap(len1, len2);
        int ind = (int) segs.size() - 1;
        if (segs[ind] == len1)
        {
            ind--;
            if (segs[ind] == len2)
                ind--;
        }
        if (ind >= 0 && segs[ind] >= len1)
        {
            continue;
        }
        if (len1 > len2)
            continue;
        if (!(len1 & 1))
            continue;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}