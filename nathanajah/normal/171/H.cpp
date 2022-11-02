#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int x,y;
int n,b;


//convert d to (x,y)


void rot(int n, int& x, int& y, int rx, int ry) {
    int t;
    if (ry == 0) {
        if (rx == 1) {
            x = n-1 - x;
            y = n-1 - y;
        }
        t  = x;
        x = y;
        y = t;
    }
}

void d2xy(int n, int d, int& x, int& y) {
    int rx, ry, s, t=d;
    x = y = 0;
    for (s=1; s<n; s*=2) {
        rx = 1 & (t/2);
        ry = 1 & (t ^ rx);
        rot(s, x, y, rx, ry);
        x += s * rx;
        y += s * ry;
        t /= 4;
    }
}
int main()
{
    scanf("%d %d",&n,&b);
    d2xy(1<<n,b,x,y);
    printf("%d %d\n",x,y);
}