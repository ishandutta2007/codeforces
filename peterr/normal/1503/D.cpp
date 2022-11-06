#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int where[2 * MAXN + 1];
bool visited[2 * MAXN + 1];
pair<int, int> a[MAXN];

int other(pair<int, int> &pr, int x)
{
    if (pr.first == x)
        return pr.second;
    return pr.first;
}

int solve(int l, int r, int n)
{
    int ans = 0;
    int left = l;
    int right = 2 * n - l + 1;
    int lb = l;
    int ub = other(a[where[l]], l);
    visited[lb] = visited[ub] = true;
    int backLeft = ub;
    int backRight = 0;
    if (a[where[l]].first != l)
        ans++;
    while (left <= r || right >= 2 * n - r + 1)
    {
        while (left <= r && visited[left])
            left++;
        while (right >= 2 * n - r + 1 && visited[right])
            right--;
        if (left <= r && left < lb)
        {
            if (a[where[left]].first != left)
            {
                swap(a[where[left]].first, a[where[left]].second);
                ans++;
            }
            ub = min(ub, a[where[left]].second);
            if (a[where[left]].second > backLeft)
                return -1;
            backLeft = a[where[left]].second;
            visited[left] = visited[other(a[where[left]], left)] = true;
        }
        else if (right >= 2 * n - r + 1 && right > ub)
        {
            if (a[where[right]].first != right)
            {
                swap(a[where[right]].first, a[where[right]].second);
                ans++;
            }
            lb = max(lb, a[where[right]].second);
            if (a[where[right]].second < backRight)
                return -1;
            backRight = a[where[right]].second;
            visited[right] = visited[other(a[where[right]], right)] = true;
        }
    }
    if (backLeft < backRight)
        return -1;
    return ans;
}

void relax(int x, int &left, int &right, int n)
{
    if (x <= n)
        left = max(left, x);
    else
        right = min(right, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fill(visited + 1, visited + 2 * n + 1, false);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, [] (pair<int, int> x, pair<int, int> y) {
         if (x.second < x.first)
            swap(x.first, x.second);
         if (y.second < y.first)
            swap(y.first, y.second);
         return x < y;
    });
    for (int i = 0; i < n; i++)
    {
        where[a[i].first] = i;
        where[a[i].second] = i;
    }
    /*
    for (int i = 0; i < n; i++)
    {
        cout << "sorted " << i << " " << a[i].first << " " << a[i].second << endl;
    }
    */
    int ptr = 0;
    int ans = 0;
    bool valid = true;
    while (ptr < n)
    {
        int oldPtr = ptr;
        int left = 0;
        int right = 2 * n + 1;
        while (ptr < n)
        {
            relax(a[ptr].first, left, right, n);
            relax(a[ptr].second, left, right, n);
            if (left == ptr + 1 && right == 2 * n - ptr)
            {
                int flips = solve(oldPtr + 1, ptr + 1, n);
                if (flips == -1)
                    valid = false;
                ans += min(flips, (ptr + 1 - oldPtr) - flips);
                break;
            }
            ptr++;
        }
        ptr++;
    }
    if (!valid)
        ans = -1;
    cout << ans << "\n";
    return 0;
}