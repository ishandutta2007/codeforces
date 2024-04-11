#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3 * 1e5;
int arr[MAXN];
int pre[MAXN];
unordered_map<int, int> even;
unordered_map<int, int> odd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            pre[i] = arr[i] ^ pre[i-1];
            if (i % 2 == 0)
            {
                if (even.find(pre[i]) == even.end())
                {
                    even[pre[i]] = 1;
                }
                else
                {
                    even[pre[i]]++;
                }
            }
            else
            {
                if (odd.find(pre[i]) == odd.end())
                {
                    odd[pre[i]] = 1;
                }
                else
                {
                    odd[pre[i]]++;
                }
            }
        }
        else
        {
            pre[i] = arr[i];
            even[pre[i]] = 1;
        }
    }
    long long pairs = 0;
    for (int i = 0; i < n; i += 2)
    {
        pairs += even[pre[i]] - 1;
    }
    for (int i = 1; i < n; i += 2)
    {
        pairs += odd[pre[i]] - 1;
    }
    if (odd.find(0) != odd.end())
        pairs += odd[0] * 2;

    cout << pairs / 2;


    return 0;
}