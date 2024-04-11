#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

int a[3001];
int b[3001];
set<int> q;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= m)
            b[a[i]]++;
    }
    int k = n / m;
    int h = k;
    if (n % m != 0)
        h++;
    int j = 0, ans = 0, t = 0;
    for (int i = 1; i <= m; i++)
    {
        while (b[i] < k && j < n)
        {
            if (a[j] > m || b[a[j]] > h || (b[a[j]] > k && q.size() >= (n % m)))
            {
                if (a[j] <= m)
                    b[a[j]]--;
                b[i]++;
                a[j] = i;
                ans++;
            }
            if (b[a[j]] == h && a[j] <= m)
                q.insert(a[j]);
            j++;
        }
    }
    cout << k << " " << ans << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}