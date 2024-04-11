#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef pair <double, int> pdi;

vector <pdi> a;

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++)
    {
        int x, y, k;
        scanf("%d %d %d", &x, &y, &k);
        a.push_back(make_pair(sqrt(x * x + y * y), k));
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
    {
        s += a[i].second;
        if (s >= 1000000)
        {
            printf("%.6f", a[i].first);
            return 0;
        }
    }
    puts("-1");
    return 0;
}