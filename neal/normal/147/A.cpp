// #define NDEBUG
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

char str[10005];

bool is_punctuation(char c)
{
    return c == '.' || c == ',' || c == '!' || c == '?';
}

int main()
{
    bool first = true;

    while (scanf("%s", str) == 1)
    {
        if (!first && !is_punctuation(str[0]))
            putchar(' ');

        first = false;
        int length = strlen(str);

        for (int i = 0; i < length; i++)
        {
            putchar(str[i]);

            if (i != length - 1 && is_punctuation(str[i]))
                putchar(' ');
        }
    }

    putchar('\n');
    return 0;
}