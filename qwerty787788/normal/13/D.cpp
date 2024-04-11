#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 1111
#define pb push_back

int nextInt()
{
    int tmp = rand();
    scanf("%d", &tmp);
    return tmp;
}

struct point
{
    int x, y, type;
    point(int x, int y, int type) : x(x), y(y), type(type) {}
    point(int x, int y) : x(x), y(y) {}
    point() : x(0), y(0), type(0) {}

    friend ostream &operator<<(ostream &os, const point &dt);
};

ostream &operator<<(ostream &os, const point &dt)
{
    os << dt.x << " " << dt.y;
    return os;
}

long long mul(point p1, point p2)
{
    return p1.x * 1L * p2.y - p1.y * 1L * p2.x;
}

point cur;

long long mul3(const point &p1, const point &p2, const point &p3)
{
    return (p2.x - p1.x) * 1LL * (p3.y - p1.y) - (p2.y - p1.y) * 1LL * (p3.x - p1.x);
}

bool cmp(point p1, point p2)
{
    //double a1 = atan2(p1.y - cur.y, p1.x - cur.x);
    //double a2 = atan2(p2.y - cur.y, p2.x - cur.x);
    //if (a1 < a2) {
    //  return true;
    //}
    //return false;
    if (p1.y >= cur.y && p2.y < cur.y)
        return true;
    if (p1.y < cur.y && p2.y >= cur.y)
        return false;
    if (mul3(cur, p1, p2) > 0)
        return true;
    return false;
}


point all[MAX];

int main ()
{
    //freopen("input.txt", "r", stdin);
    int n = nextInt();
    int m = nextInt();
    vector<point> red;
    for (int i = 0; i < n; i++)
    {
        int x = nextInt();
        int y = nextInt();
        red.pb(point(x, y, 0));
    }
    vector<point> blue;
    for (int i = 0 ; i < m; i++)
    {
        int x = nextInt();
        int y = nextInt();
        blue.pb(point(x, y, 1));
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cur = red[i];
        int sz = 0;
        for (int j = i + 1; j < n; j++)
            all[sz++] = red[j];
        for (int j = 0; j < m; j++)
            all[sz++] = blue[j];
        sort(all, all + sz, cmp);
        for (int j = 0; j < sz; j++)
        {
            if (all[j].type == 0)
            {
                int best_id = -1;
                for (int k = (j + 1) % sz; k != j; k = (k + 1))
                {
                    if (k == sz) k = 0;
                    long long r = mul3(cur, all[j], all[k]);
                    if (r <= 0)
                        break;
                    if (all[k].type == 0)
                    {
                        if (best_id == -1 || mul3(all[j], all[k], all[best_id]) < 0)
                        {
                            //cout << cur << " "<< all[j] << " " << all[k] << endl;
                            res++;
                        }
                    }
                    else
                    {
                        if (best_id == -1 || mul3(all[j], all[k], all[best_id]) < 0)
                        {
                            best_id = k;
                        }
                    }
                }
            }
        }
    }
    cout << res << endl;
}