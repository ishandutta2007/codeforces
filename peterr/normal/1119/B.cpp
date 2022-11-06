#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E3;
int bottles[MAXN];

int main()
{
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; i++)
        cin >> bottles[i];
    int ans = 0;
    multiset<int> bst;
    for (int i = 0; i < n; i++)
    {
        bst.insert(bottles[i]);
        auto it = bst.end();
        it--;
        int height = 0;
        for (int j = 0; j < (i+1) / 2; j++)
        {
            int b1 = *it;
            it--;
            int b2 = *it;
            it--;
            height += b1;
        }
        if (i % 2 == 0)
            height += *bst.begin();
        if (height > h)
        {
            break;
        }
        else
        {
            ans = i;
        }
    }
    cout << ans + 1;
    return 0;
}