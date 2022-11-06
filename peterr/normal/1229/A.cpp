#include <bits/stdc++.h>

using namespace std;

const int MAXN = 7000;
long long a[MAXN];
int b[MAXN];
bool visited[MAXN];
long long val[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        vector<int> v;
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (visited[j])
                continue;
            if (i != j && a[i] == a[j])
                found = true;
            if ((a[i] | a[j]) == a[i])
            {
                v.push_back(j);
            }
        }
        if (found)
        {
            for (int k : v)
            {
                visited[k] = true;
                ans += b[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}