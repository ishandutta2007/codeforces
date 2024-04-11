#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> ans;
int a, b, c;

void solve(int x)
{
    long long res = x;
    for (int i = 2; i <= a; i++) res *= x;
    res *= b;
    res += c;
    if (res <= 0 || res >= 1000000000) return;
    int sum = 0;
    for (long long help = res; help > 0; help /= 10) sum += help % 10;
    if (sum != x) return;
    ans.push_back((int)res);
}

int main()
{
    scanf("%d %d %d", &a, &b, &c);
    for (int i = 1; i <= 81; i++) solve(i);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    return 0;
}