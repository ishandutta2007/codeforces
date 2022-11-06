#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int points[MAXN];
int ans = 0;

bool check(int leftEnd, int n, int z)
{
    if (leftEnd < 0 || leftEnd >= n)
        return false;
    int i = leftEnd;
    int j = n - 1;
    int pairs = 0;
    while (j > leftEnd && i >= 0)
    {
        while (i >= 0 && points[j] - points[i] < z)
            i--;
        if (i >= 0)
            pairs++;
        i--;
        j--;
    }
    ans = max(ans, pairs);
    return i < 0;
}

int main()
{
    int n, z;
    cin >> n >> z;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i];
    }
    sort(points, points + n);
    int leftEnd = 0;
    for (int jump = n / 2 + 1; jump > 0; jump /= 2)
    {
        while (leftEnd + jump < n && check(leftEnd + jump, n, z))
            leftEnd += jump;
    }
    for (int i = -3; i <= 3; i++)
        check(leftEnd + i, n, z);
    cout << ans << endl;
    return 0;
}