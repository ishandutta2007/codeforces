#include<bits/stdc++.h>
/*
3 1 7 1.80952 0.714286
5 1 3 1.55556 0.333333
7 3 9 2 1
*/


using namespace std;

const int maxN = 1e6 + 10;
const long double eps = 1e-9;
struct Point
{
    long double x;
    long double y;
};

struct bracket
{
    int mask;
    int sum;
    Point t;
    int area;
};

long double a, b;
int n;
bracket l[maxN], r[maxN];
int poc[maxN], ende[maxN];

inline bool cmp(bracket x, bracket y)
{
    return x.sum < y.sum;
}

inline Point triangle(Point p1, Point p2, Point p3)
{
    return {(p1.x + p2.x + p3.x) /3.00, (p1.y + p2.y + p3.y) / 3.00};
}

inline Point rectangle(Point p1, Point p2, Point p3, Point p4)
{
    return {(p1.x + p2.x + p3.x + p4.x) /4.00, (p1.y + p2.y + p3.y + p4.y) / 4.00};
}

inline Point teziste(Point p1, int area1, Point p2, int area2)
{
    return {(p1.x * area1 + p2.x * area2)/(area1 + area2),  (p1.y * area1 + p2.y * area2)/(area1 + area2)};
}
int main()
{
    cin>>n>>a>>b;

    int half = n/2;
    int cur = 0;
    for (int mask = 0; mask < (1<<half); mask++)
    {
        int sum = 0;
        int area = 0;
        Point curT = {0, 0};
        int ok = 1;
        int cx = 0;
        int cy = 0;

        for (int i = 0; i<half; i++)
        {
            if (mask&(1<<i))
            {
                sum++;
                Point tt = triangle({cx, cy}, {cx + 1, cy}, {cx + 1, cy + 1});
                Point tr = rectangle({cx, cy}, {cx + 1, cy}, {cx, 0}, {cx + 1, 0});
                if (i == 0) curT = teziste(tt, 1,  tr, cy * 2); else
                curT =teziste(curT, area, teziste(tt, 1,  tr, cy * 2), 2*cy + 1);
                area+=2*cy + 1;
                cy++;
                cx++;

            }
            else
            {
                sum--;
                if (sum < 0) ok = 0;
                Point tt = triangle({cx, cy}, {cx, cy - 1}, {cx + 1, cy - 1});
                Point tr = rectangle({cx, cy - 1}, {cx + 1, cy - 1}, {cx, 0}, {cx + 1, 0});
                if (i == 0) curT =  teziste(tt, 1, tr, 2*cy - 2); else
                curT =teziste(curT, area, teziste(tt, 1, tr, 2*cy - 2), 2*cy - 1);
                area+=2*cy - 1;
                cy--;
                cx++;
            }
        }

        if (ok)
        {
            l[++cur] = {mask, sum, curT, area};
            r[cur] = {mask, sum, {n - curT.x, curT.y}, area};
        }
    }

    sort(l + 1, l + cur + 1, cmp);
    sort(r + 1, r + cur + 1, cmp);

    for (int i = 1; i<=cur; i++)
    {
        if (!poc[r[i].sum]) poc[r[i].sum] = i;
        ende[r[i].sum] = i;
    }

    int nasao = 0;

    for (int i = 1; i<=cur && !nasao; i++)
        for (int j = poc[l[i].sum]; j<=ende[l[i].sum] && !nasao; j++)
        {
            Point t = teziste(l[i].t, l[i].area, r[j].t, r[j].area);
            if (abs(t.x - a) < eps && abs(t.y - b) < eps)
            {
                nasao = 1;

                for (int w = 0; w< half; w++)
                    if (l[i].mask&(1<<w)) printf("(");
                    else printf(")");

                for (int w = half - 1; w>=0; w--)
                    if (r[j].mask & ( 1<<w)) printf(")");
                    else printf("(");
                return 0;
            }
        }
}