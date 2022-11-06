#include <bits/stdc++.h>

using namespace std;

int findN(int x)
{
    int index = 32 - __builtin_clz(x);
    while (index >= 0 && (x & (1 << (index - 1))))
        index--;
    return index;
}

int main()
{
    int x;
    cin >> x;
    vector<int> ans;
    int steps = 0;
    while (__builtin_popcount(x + 1) != 1)
    {
        steps++;
        int index = findN(x);
        ans.push_back(index);
        x = x ^ ((1 << index) - 1);
        if (__builtin_popcount(x + 1) == 1)
            break;
        x++;
        steps++;
    }

    cout << steps << endl;
    for (int i : ans)
        cout << i << " ";

    return 0;
}