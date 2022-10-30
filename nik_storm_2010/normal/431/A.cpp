#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 200000;

int main()
{
    int a1, a2, a3, a4;
    scanf("%d %d %d %d", &a1, &a2, &a3, &a4);
    char s[N];
    scanf("%s", &s);
    int ans = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '1') ans += a1;
        if (s[i] == '2') ans += a2;
        if (s[i] == '3') ans += a3;
        if (s[i] == '4') ans += a4;
    }
    printf("%d\n", ans);
    return 0;
}