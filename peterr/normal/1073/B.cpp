#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 2E5;
int id[MAXN + 1];
int a[MAXN + 1];
int b[MAXN + 1];
bool visited[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        id[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b[i] = id[b[i]];
    }
    stringstream ss;
    int top = 1;
    for (int i = 1; i <= n; i++)
    {
        ss << max(0, b[i] - top + 1) << " ";
        top = max(top, b[i] + 1);
    }
    cout << ss.str() << endl;
    return 0;
}