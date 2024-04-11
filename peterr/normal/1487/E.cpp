#include <bits/stdc++.h>

using namespace std;

const int MAXN = 150000;
int a[MAXN + 1];
int b[MAXN + 1];
int c[MAXN + 1];
int d[MAXN + 1];
set<int> bad[MAXN + 1];

void readIn(int n, int arr[MAXN + 1])
{
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
}

void advance(vector<pair<int, int>> &vec, int n2, int arr[MAXN + 1])
{
    int m;
    cin >> m;
    for (int i = 1; i <= n2; i++)
        bad[i].clear();
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        bad[y].insert(x);
    }
    sort(vec.begin(), vec.end());
    vector<pair<int, int>> temp;
    for (int i = 1; i <= n2; i++)
    {
        int ptr = 0;
        while (ptr < (int) vec.size() && bad[i].count(vec[ptr].second))
            ptr++;
        if (ptr == (int) vec.size())
            continue;
        temp.push_back({arr[i] + vec[ptr].first, i});
    }
    swap(temp, vec);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    readIn(n1, a);
    readIn(n2, b);
    readIn(n3, c);
    readIn(n4, d);
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n1; i++)
    {
        vec.push_back({a[i], i});
    }
    advance(vec, n2, b);
    advance(vec, n3, c);
    advance(vec, n4, d);
    sort(vec.begin(), vec.end());
    if (vec.empty())
        cout << "-1\n";
    else
        cout << vec[0].first << "\n";
    return 0;
}