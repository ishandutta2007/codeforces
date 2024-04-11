#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct point
{
    int x, y, z;
};

bool comp(point a, point b)
{
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    point cc;
    scanf("%d", &n);
    vector <vector <point> > a(10000);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &cc.x, &cc.y);
        cc.z = i + 1;
        a[cc.x / 1000].push_back(cc);
    }
    for (int i = 0; i < 10000; i++)
    {
        if (a[i].size() != 0)
        {
            sort(a[i].begin(), a[i].end(), comp);
            if (i % 2 == 1)
                reverse(a[i].begin(), a[i].end());
            for (int j = 0; j < a[i].size(); j++)
                printf("%d ", a[i][j].z);
        }
    }
    return 0;
}