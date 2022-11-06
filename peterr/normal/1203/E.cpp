#include <bits/stdc++.h>

using namespace std;

const int MAXN = 150000;
int weight[MAXN];
bool has[MAXN + 2];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    sort(weight, weight + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = max(1, weight[i] - 1); j <= weight[i] + 1; j++)
        {
            if (!has[j])
            {
                has[j] = true;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}