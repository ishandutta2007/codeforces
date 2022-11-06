#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3 * 1E5;
vector<int> children[MAXN + 1];
int parent[MAXN + 1];
bool isMax[MAXN + 1];
bool isLeaf[MAXN + 1];
int leaves[MAXN + 1];

void countLeaves(int i)
{
    if (isLeaf[i])
        leaves[i] = 1;
    else
    {
        int l = 0;
        for (int child : children[i])
        {
            countLeaves(child);
            l += leaves[child];
        }
        leaves[i] = l;
    }

}

int solve(int i)
{
    if (isLeaf[i])
        return 0;
    if (isMax[i])
    {
        int most = 0;
        int child = 0;
        int minLeaves = MAXN + 5;
        for (int c : children[i])
        {
            most = max(most, leaves[i] - leaves[c] + solve(c));
        }
        return most;
    }
    else
    {
        int total = 0;
        for (int c : children[i])
            total += solve(c);
        return total;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> isMax[i];
    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i];
        children[parent[i]].push_back(i);
    }

    fill(isLeaf, isLeaf + n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        isLeaf[parent[i]] = false;
    }
    countLeaves(1);
    cout << solve(1) + 1;

    return 0;
}