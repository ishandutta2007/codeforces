#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        sum += x;
    }
    sum += 10 * (n - 1);
    if (sum > d) puts("-1"); else printf("%d\n", (d - sum) / 5 + (n - 1) * 2);
    return 0;
}