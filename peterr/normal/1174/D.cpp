#include <bits/stdc++.h>

using namespace std;

int n, x;
bool visited[1 << 18];
vector<int> b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    visited[x] = true;
    for (int i = 1; i < (1 << n); i++)
    {
        if (!visited[i])
        {
            b.push_back(i);
            visited[i] = true;
            visited[i ^ x] = true;
        }
    }

    cout << b.size() << endl;
    for (int i = 0; i < b.size(); i++)
    {
        if (i == 0)
            cout << b[i] << " ";
        else
            cout << (b[i] ^ b[i-1]) << " ";
    }

    return 0;
}