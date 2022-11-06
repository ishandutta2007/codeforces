#include <iostream>
#include <vector>

using namespace std;

void doSwap(int* p, int* index, int n, int pos1, int pos2, vector<pair<int, int>> &swaps)
{
    if (pos1 == pos2)
        return;
    else if (abs(pos1 - pos2) >= n / 2)
    {
        swaps.push_back({pos1, pos2});
        int a = p[pos1], b = p[pos2];
        swap(p[pos1], p[pos2]);
        swap(index[a], index[b]);
        return;
    }

    int mid1 = n / 2;
    int mid2 = n / 2 + 1;
    if ((pos1 == mid1 || pos1 == mid2) && (pos2 == mid1 || pos2 == mid2))
    {
        if (pos1 != mid1)
            swap(pos1, pos2);
        doSwap(p, index, n, pos2, 1, swaps);
        doSwap(p, index, n, 1, n, swaps);
        doSwap(p, index, n, n, pos1, swaps);
        doSwap(p, index, n, 1, n, swaps);
        doSwap(p, index, n, 1, pos2, swaps);
    }
    else if (pos1 == mid1 || pos2 == mid1)
    {
        if (pos1 != mid1)
            swap(pos1, pos2);
        if (pos2 < pos1)
        {
            doSwap(p, index, n, pos2, n, swaps);
            doSwap(p, index, n, n, pos1, swaps);
        }
        else
        {
            doSwap(p, index, n, pos2, 1, swaps);
            doSwap(p, index, n, 1, n, swaps);
            doSwap(p, index, n, n, pos1, swaps);
        }
    }
    else if (pos1 == mid2 || pos2 == mid2)
    {
        if (pos1 != mid1)
            swap(pos1, pos2);
        if (pos2 > pos1)
        {
            doSwap(p, index, n, pos2, 1, swaps);
            doSwap(p, index, n, 1, pos1, swaps);
        }
        else
        {
            doSwap(p, index, n, pos2, n, swaps);
            doSwap(p, index, n, n, 1, swaps);
            doSwap(p, index, n, 1, pos1, swaps);
        }
    }
    else if (pos1 < mid1 && pos2 < mid1)
    {
        doSwap(p, index, n, pos1, n, swaps);
        doSwap(p, index, n, n, pos2, swaps);
        doSwap(p, index, n, n, pos1, swaps);
    }
    else if (pos1 > mid2 && pos2 > mid2)
    {
        doSwap(p, index, n, pos1, 1, swaps);
        doSwap(p, index, n, 1, pos2, swaps);
        doSwap(p, index, n, 1, pos1, swaps);
    }
    else
    {
        if (pos1 > mid2)
            swap(pos1, pos2);
        doSwap(p, index, n, pos1, n, swaps);
        doSwap(p, index, n, pos2, 1, swaps);
        doSwap(p, index, n, 1, n, swaps);
        doSwap(p, index, n, 1, pos2, swaps);
        doSwap(p, index, n, n, pos1, swaps);
    }
}

int main()
{
    int n;
    cin >> n;
    int* p = new int[n+1];
    int* index = new int[n+1];
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        p[i] = num;
        index[num] = i;
    }

    vector<pair<int, int>> swaps;
    doSwap(p, index, n, index[n/2], n/2, swaps);
    doSwap(p, index, n, index[n/2+1], n/2+1, swaps);
    for (int i = 1; i <= n; i++)
    {
        doSwap(p, index, n, index[i], i, swaps);
    }

    cout << swaps.size() << endl;
    for (int i = 0; i < swaps.size(); i++)
    {
        cout << swaps[i].first << " " << swaps[i].second<< endl;
    }

    return 0;
}