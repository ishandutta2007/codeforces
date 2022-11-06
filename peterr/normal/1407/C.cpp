#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E4;
int a[MAXN + 1];
bool visited[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    while ((int) v.size() >= 2)
    {
        int p = v.back();
        v.pop_back();
        int q = v.back();
        v.pop_back();
        cout << "? " << p << " " << q << endl;
        int x, y;
        cin >> x;
        cout << "? " << q << " " << p << endl;
        cin >> y;
        if (x > y)
        {
            a[p] = x;
            visited[x] = true;
            v.push_back(q);
        }
        else
        {
            a[q] = y;
            visited[y] = true;
            v.push_back(p);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            a[v.back()] = i;
            break;
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}