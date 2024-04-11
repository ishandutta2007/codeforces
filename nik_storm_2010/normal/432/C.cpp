#include <cstdio>
#include <vector>

using namespace std;
typedef pair <int, int> pii;
const int N = 100000 + 10;

bool prime[N];
int a[N], ps[N];
vector <pii> ans;

bool check(int x)
{
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return true;
}

void movefrom(int i, int j)
{
    if (i == j) return;
    for (int x = i; x <= j; x++) if (prime[j - x + 1])
    {
        ans.push_back(make_pair(x, j));
        ps[a[x]] = j, ps[a[j]] = x;
        int h = a[x];
        a[x] = a[j], a[j] = h;
        movefrom(i, x);
        break;
    }
}

int main()
{
    for (int i = 2; i < N; i++) prime[i] = check(i);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        ps[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == i) continue;
        movefrom(i, ps[i]);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}