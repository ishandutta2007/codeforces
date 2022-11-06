#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int arr[MAXN];

int main()
{
    int n;
    cin >> n;
    int maxx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxx = max(maxx, arr[i]);
    }
    int i = 0;
    int ans = 1;
    while (i < n)
    {
        if (arr[i] == maxx)
        {
            int cnt = 0;
            int j = i;
            while (j < n && arr[j] == maxx)
            {
                j++;
                cnt++;
            }
            ans = max(ans, cnt);
            i = j;
        }
        else
            i++;
    }
    cout << ans << endl;
    return 0;
}