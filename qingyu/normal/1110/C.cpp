//Qingyu
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <cctype>
#include <cstdlib>

int q;

inline char nc()
{
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
    int res = 0;
    char ch;
    do ch = nc(); while (ch < 48 || ch > 57);
    do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
    return res;
}

inline void solve(int x)
{
if (x == 1) printf("0\n");
else if (x == 3) printf("1\n");
else if (x == 7) printf("1\n");
else if (x == 15) printf("5\n");
else if (x == 31) printf("1\n");
else if (x == 63) printf("21\n");
else if (x == 127) printf("1\n");
else if (x == 255) printf("85\n");
else if (x == 511) printf("73\n");
else if (x == 1023) printf("341\n");
else if (x == 2047) printf("89\n");
else if (x == 4095) printf("1365\n");
else if (x == 8191) printf("1\n");
else if (x == 16383) printf("5461\n");
else if (x == 32767) printf("4681\n");
else if (x == 65535) printf("21845\n");
else if (x == 131071) printf("1\n");
else if (x == 262143) printf("87381\n");
else if (x == 524287) printf("1\n");
else if (x == 1048575) printf("349525\n");
else if (x == 2097151) printf("299593\n");
else if (x == 4194303) printf("1398101\n");
else if (x == 8388607) printf("178481\n");
else if (x == 16777215) printf("5592405\n");
else if (x == 33554431) printf("1082401\n");
else {
int t = 1;
while (t <= x) t <<= 1;
printf("%d\n", t - 1); 
}
}

int main()
{
    q = read();
    while (q--)
    {
    	int x = read();
		solve(x);	
    }
}