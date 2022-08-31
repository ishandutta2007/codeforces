#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int INF = 1000000005;

inline int rev (int n)
{
    int r = 0;

    while (n > 0)
    {
        r = r * 10 + n % 10;
        n /= 10;
    }

    return r;
}

inline pair <int, int> get (int n)
{
    int r = rev (n), g = __gcd (n, r);
    return make_pair (n / g, r / g);
}

inline pair <int, int> flip (pair <int, int> p)
{
    return make_pair (p.second, p.first);
}

int X, Y, W;
int bestx = INF, besty = INF;
map <pair <int, int>, int> mapx, mapy;

int main ()
{
    scanf ("%d %d %d", &X, &Y, &W);

    for (int y = 1; y <= Y; y++)
        mapy [flip (get (y))]++;

    long long lucky = 0;

    for (int x = 1, y = Y; x <= X; x++)
    {
        lucky += mapy [get (x)];
        mapx [get (x)]++;

        while (y > 0 && lucky - mapx [flip (get (y))] >= W)
        {
            lucky -= mapx [flip (get (y))];
            mapy [flip (get (y))]--;
            y--;
        }

        if (lucky >= W && (long long) x * y < (long long) bestx * besty)
        {
            bestx = x;
            besty = y;
        }
    }

    if (bestx == INF)
        puts ("-1");
    else
        printf ("%d %d\n", bestx, besty);

    return 0;
}