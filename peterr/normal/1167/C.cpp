#include <iostream>
#include <vector>

using namespace std;

int getRoot(int* parent, int i)
{
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

void unite(int* parent, int* size, int* height, int a, int b)
{
    int r1 = getRoot(parent, a);
    int r2 = getRoot(parent, b);
    if (r1 != r2)
    {
        if (height[r1] > height[r2])
        {
            parent[r2] = r1;
            size[r1] += size[r2];
            height[r1] = max(height[r1], 1 + height[r2]);
        }
        else
        {
            parent[r1] = r2;
            size[r2] += size[r1];
            height[r2] = max(height[r2], 1 + height[r1]);
        }
    }

}

int main()
{
    int n, m;
    cin >> n >> m;
    int* parent = new int[n + 1];
    int* size = new int[n + 1];
    int* height = new int[n+1];
    fill(height, height + n + 1, 0);
    fill(size, size + n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        int first;
        if (k > 0)
        {
            cin >> first;
        }
        for (int j = 1; j < k; j++)
        {
            int cur;
            cin >> cur;
            unite(parent, size, height, cur, first);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << size[getRoot(parent, i)] << " ";
    }

    return 0;
}