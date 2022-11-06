#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int parent[MAXN + 1];
bool norespect[MAXN + 1];
bool canDelete[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fill(canDelete + 1, canDelete + n + 1, true);
    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> parent[i] >> norespect[i];
        if (parent[i] == -1)
            root = i;
        if (!norespect[i])
        {
            canDelete[i] = false;
            canDelete[parent[i]] = false;
        }
    }
    stringstream ss;
    bool found = false;
    for (int i = 1; i <= n; i++)
    {
        if (i == root)
            continue;
        if (canDelete[i])
        {
            found = true;
            ss << i << " ";
        }
    }
    if (found)
    {
        cout << ss.str();
    }
    else
    {
        cout << -1;
    }
    return 0;
}