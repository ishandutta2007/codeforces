#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];

void movePtrs(int need, int &left, int &right)
{
    right = left;
    while (need)
    {
        int amt = min(a[right], need);
        a[right] -= amt;
        need -= amt;
        if (need)
            right++;
    }
}

bool canReach(int startPos, int endPos, int d)
{
    if (endPos >= startPos)
        return true;
    int cycles = (startPos - endPos + d - 1) / d;
    return cycles <= endPos + 1;
}

int solve(int rooms, int d, int b)
{
    int curRoom = 0;
    int ans = rooms;
    int left = 0;
    while (a[left] == 0)
        left++;
    int right = left;
    movePtrs(b, left, right);
    while (curRoom < rooms)
    {
        if (canReach(left, curRoom, d) && canReach(right, curRoom, d))
        {
            ans--;
            if (curRoom + 1 < rooms)
            {
                left = right;
                while (a[left] == 0)
                    left++;
                movePtrs(b, left, right);
            }
        }
        curRoom++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d, b;
    cin >> n >> d >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x1 = solve((n + 1) / 2, d, b);
    reverse(a, a + n);
    int x2 = solve(n / 2, d, b);
    cout << max(x1, x2) << "\n";
    return 0;
}