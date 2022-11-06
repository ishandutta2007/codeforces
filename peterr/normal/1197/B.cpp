#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int pillars[MAXN];

int main()
{
    int n;
    cin >> n;
    int center;
    for (int i = 0; i < n; i++)
    {
        cin >> pillars[i];
        if (pillars[i] == n)
            center = i;
    }
    int left = center - 1;
    int right = center + 1;
    bool valid = true;
    int cur = n;
    while (left >= 0 || right < n)
    {
        if (left >= 0 && pillars[left] == cur - 1)
        {
            left--;
        }
        else if (right < n && pillars[right] == cur - 1)
        {
            right++;
        }
        else
        {
            valid = false;
            break;
        }
        cur--;
    }
    if (valid)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}