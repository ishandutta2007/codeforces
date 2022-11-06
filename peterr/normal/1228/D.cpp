#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int parent[MAXN + 1];
int s[MAXN + 1];
vector<int> adjList[MAXN + 1];

int getRoot(int a)
{
    if (parent[a] != a)
        parent[a] = getRoot(parent[a]);
    return parent[a];
}

void un(int a, int b)
{
    int r1 = getRoot(a);
    int r2 = getRoot(b);
    if (r1 == r2)
        return;
    if (s[r1] > s[r2])
        swap(r1, r2);
    parent[r1] = r2;
    s[r2] += s[r1];
}

int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        s[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int comps = 0;
    bool possible = true;
    int r1, r2, r3;
    r1 = r2 = r3 = -1;
    for (int i = 1; i <= n; i++)
    {
        if (comps == 0)
        {
            comps++;
            r1 = i;
        }
        else
        {
            bool in1 = false, in2 = false, in3 = false;
            for (int adj : adjList[i])
            {
                if (adj > i)
                    continue;
                int root = getRoot(adj);
                if (root == r1)
                    in1 = true;
                else if (root == r2)
                    in2 = true;
                else if (root == r3)
                    in3 = true;
            }
            if (comps == 1)
            {
                if (in1)
                {
                    comps++;
                    r2 = i;
                }
                else
                {
                    un(i, r1);
                    r1 = getRoot(i);
                }
            }
            else if (comps == 2)
            {
                if (in1 && in2)
                {
                    comps++;
                    r3 = i;
                }
                else if (in1)
                {
                    un(i, r2);
                    r2 = getRoot(i);
                }
                else if (in2)
                {
                    un(i, r1);
                    r1 = getRoot(i);
                }
                else
                {
                    possible = false;
                    break;
                }
            }
            else if (comps == 3)
            {
                if (!in1 && in2 && in3)
                {
                    un(i, r1);
                    r1 = getRoot(i);
                }
                else if (in1 && !in2 && in3)
                {
                    un(i, r2);
                    r2 = getRoot(i);
                }
                else if (in1 && in2 && !in3)
                {
                    un(i, r3);
                    r3 = getRoot(i);
                }
                else
                {
                    possible = false;
                    break;
                }
            }
        }
    }

    int a = s[r1], b = s[r2], c = s[r3];
    if (m != (long long) a * (b + c) + (long long) b * c)
    {
        possible = false;
    }

    if (possible && comps == 3)
    {
        for (int i = 1; i <= n; i++)
        {
            int r = getRoot(i);
            if (r == r1)
                cout << 1 << " ";
            else if (r == r2)
                cout << 2 << " ";
            else if (r == r3)
                cout << 3 << " ";
        }
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}