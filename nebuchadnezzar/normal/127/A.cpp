#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

struct point
{
    double x, y;
};

double lenvec(point a, point b)
{
    return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

int n, k;

int main()
{
    cin >> n >> k;
    /*
    point a, b;
    a.x = 3;
    a.y = 1;
    b.x = -5;
    b.y = 6;
    cout << lenvec(a, b);
    */

    int i;
    double len = 0.0;
    point a, b;
    cin >> a.x >> a.y;
    for(i = 1; i < n; ++i)
    {
        cin >> b.x >> b.y;
        len = len + lenvec(a, b);
        a.x = b.x;
        a.y = b.y;
        //cout << len;
    }
    //printf("%.6lf\n", len);
    len = len * k / 50.0;
    printf("%.6lf", len);

    return 0;
}