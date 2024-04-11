#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 200;

vector <int> a;

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < a.size() - 1; i++) sum += a[i];
    if (sum <= s) puts("YES"); else puts("NO");
    return 0;
}