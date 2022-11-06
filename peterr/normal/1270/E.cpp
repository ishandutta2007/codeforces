#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E3;
pair<int, int> pts[MAXN + 1];

void print(int n)
{
    cout << "print" << endl;
    for (int i = 1; i <= n; i++)
        cout << pts[i].first << " " << pts[i].second << endl;
}

bool isChecker(int n)
{
    //print(n);
    for (int i = 2; i <= n; i++)
    {
        if ((pts[i].first - pts[1].first + pts[i].second - pts[1].second) % 2 != 0)
        {
            return false;
        }
    }
    return true;
}



void tr(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int x = pts[i].first;
        int y = pts[i].second;
        if ((x + y) % 2 != 0)
        {
            x++;
        }
        pts[i] = {(x + y) / 2, (y - x) / 2};
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pts[i].first >> pts[i].second;
    }
    while (isChecker(n))
        tr(n);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if ((pts[i].first + pts[i].second) % 2 == 0)
            ans.push_back(i);
    }
    cout << (int) ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}