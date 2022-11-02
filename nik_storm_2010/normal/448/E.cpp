#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 10000;
const int LIM = 1e5;

vector <ll> all[N], a;
int cnt;

void build(int nom, ll last)
{
    if (last == 0 || nom == 0)
    {
        printf("%I64d ", a[nom]);
        cnt++;
        return;
    }
    for (int i = 0; i < all[nom].size(); i++)
    {
        build(all[nom][i], last - 1);
        if (cnt == LIM) return;
    }
}

int main()
{
    ll x, k;
    scanf("%I64d %I64d", &x, &k);
    for (ll i = 1; i * i <= x; i++) if (x % i == 0)
    {
        a.push_back(i);
        if (x / i != i) a.push_back(x / i);
    }
    sort(a.begin(), a.end());
    int n = a.size();
    for (int i = 0; i < n; i++) for (int j = 0; j <= i; j++) if (a[i] % a[j] == 0) all[i].push_back(j);
    build(n - 1, k);
    return 0;
}