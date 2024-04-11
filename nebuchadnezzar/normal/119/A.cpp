#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int nod(int x, int y)
{
    int pr = max(x, y);
    int r = min(x, y);
    x = pr;
    y = r;
    while(r != 0)
    {
        pr = r;
        r = x % y;
        x = y;
        y = r;
    }
    return pr;
}

int a, b, n;

int main()
{
    cin >> a >> b >> n;

    while(true)
    {
        if(nod(a, n) > n)
        {
            cout << "1";
            return 0;
        }
        else
        {
            n = n - nod(a, n);
        }
        if(nod(b, n) > n)
        {
            cout << "0";
            return 0;
        }
        else
        {
            n = n - nod(b, n);
        }
    }
    return 0;
}