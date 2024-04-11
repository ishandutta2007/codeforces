#pragma comment(linker,"/STACK:200000000")
#include <stdio.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <limits.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eps (double)(1e-12)
#define MOD (int)(1e9+7)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

string s1, s2;
int k;
bool rekurs(int l1, int r1, int l2, int r2)
{
    int i;
    if ((r1 - l1) % 2 == 0)
    {
        int j = l2;
        for (i = l1; i <= r1; ++i)
        {
            if (s1[i] != s2[j])
                return false;
            j++;
        }
        return true;
    }
    int m1, m2;
    m1 = (r1 + l1) / 2;
    m2 = (r2 + l2) / 2;
    return ((rekurs(l1, m1, l2, m2) && rekurs(m1 + 1, r1, m2 + 1, r2)) || (rekurs(l1, m1, m2 + 1, r2) && rekurs(m1 + 1, r1, l2, m2)));
}
int main()
{
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin >> s1;
    cin >> s2;
    if (rekurs(0, s1.length()-1, 0, s2.length()-1))
        printf("YES");
    else
        printf("NO");
    return 0;
}