#include <bits/stdc++.h>

using namespace std;

const int MAXK = 1E5;
int ans[MAXK];

bool solve(int n, int k, int index)
{
    if (k == 0)
        return n == 0;
    int num = (n - (long long) k * (k + 1) / 2) / k + 1;
    if (index > 0)
    {
        while (num > ans[index - 1] * 2)
            num--;
        if (num <= ans[index - 1])
            return false;
    }
    ans[index] = num;
    return solve(n - num, k - 1, index + 1);
}

int main()
{
    int n, k;
    cin >> n >> k;
    stringstream ss;
    if (solve(n, k, 0))
    {
        ss << "YES" << endl;
        for (int i = 0; i < k; i++)
            ss << ans[i] << " ";
        ss << endl;
    }
    else
    {
        ss << "NO" << endl;
    }
    cout << ss.str();
    return 0;
}