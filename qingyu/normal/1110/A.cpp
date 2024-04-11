//By Qingyu
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

int b, k;

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

int main()
{
    b = read(), k = read();
    int res = 0;
    for (int i = 1; i <= k; ++i)
    {
        int a = read();
        res = (res * b + a) % 2;
    }
    printf(res & 1 ? "odd" : "even");
}