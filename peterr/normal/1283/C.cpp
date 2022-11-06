#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN + 1];
bool visited[MAXN + 1];

int main()
{
    vector<int> pos;
    unordered_set<int> sad;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        visited[a[i]] = true;
        if (a[i] == 0)
        {
            pos.push_back(i);
            sad.insert(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && sad.find(i) != sad.end())
        {
            a[i] = i;
            visited[i] = true;
        }
    }
    int cur = n;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            while (visited[cur])
            {
                cur--;
            }
            a[i] = cur;
            visited[cur] = true;
        }
    }
    if (!pos.empty())
    {
        int temp = a[pos[0]];
        for (int i = 1; i < (int) pos.size(); i++)
        {
            int t = a[pos[i]];
            a[pos[i]] = temp;
            temp = t;
        }
        a[pos[0]] = temp;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            cout << " ";
        cout << a[i];
    }

    cout << endl;

    return 0;
}