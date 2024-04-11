#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int id;
    int sign;
    long long side;
};

const int MAXN = 1000;
Point points[MAXN + 1];

bool cmp(Point a, Point b)
{
    if (a.sign == b.sign)
    {
        if (a.sign < 0)
            return a.side < b.side;
        return b.side < a.side;
    }
    return a.sign < b.sign;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        points[i].id = i;
    }
    int nextP = 2;
    for (int i = 3; i <= n; i++)
    {
        printf("2 %d %d %d\n", 1, nextP, i);
        fflush(stdout);
        int sign;
        cin >> sign;
        if (sign < 0)
            nextP = i;
    }
    int biggest = 1;
    long long dist = -1;
    for (int i = 2; i <= n; i++)
    {
        if (i == nextP)
            continue;
        printf("1 %d %d %d\n", 1, nextP, i);
        fflush(stdout);
        cin >> points[i].side;
        if (points[i].side > dist)
        {
            dist = points[i].side;
            biggest = i;
        }
    }
    points[1].side = 0;
    points[nextP].side = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i == nextP || i == biggest)
            continue;
        printf("2 %d %d %d\n", 1, biggest, i);
        fflush(stdout);
        cin >> points[i].sign;
    }
    points[1].sign = -500;
    points[nextP].sign = -499;
    points[biggest].sign = 0;
    sort(points + 1, points + n + 1, cmp);
    cout << 0 << " ";
    for (int i = 1; i <= n; i++)
    {
        cout << points[i].id << " ";
    }
    cout << endl;
    return 0;
}