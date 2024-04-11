#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
const int N = 200000;

struct point
{
    ll x, y;
};

ll num[N], ans;
point a[N];

bool cmp_x(const point &a, const point &b)
{
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

bool cmp_y(const point & a, const point & b)
{
	return (a.y < b.y);
}

void upd_ans(const point &a, const point &b)
{
    ans = min(ans, (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void rec(int l, int r)
{
	if (r - l <= 3)
    {
        for (int i = l; i <= r; i++) for (int j = i + 1; j <= r; j++) upd_ans(a[i], a[j]);
		sort (a + l, a + r + 1, &cmp_y);
		return;
	}
	int m = (l + r) >> 1;
	ll midx = a[m].x;
	rec(l, m);
    rec(m + 1, r);
	static point t[N];
	merge(a + l, a + m + 1, a + m + 1, a + r + 1, t, &cmp_y);
	copy(t, t + r - l + 1, a + l);
    int tsz = 0;
	for (int i = l; i <= r; ++i)
    if ((a[i].x - midx) * (a[i].x - midx) < ans)
    {
        for (int j = tsz - 1; j >= 0 && (a[i].y - t[j].y) * (a[i].y - t[j].y) < ans; --j) upd_ans(a[i], t[j]);
        t[tsz++] = a[i];
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%I64d", &num[i]);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += num[i];
        a[i].x = i;
        a[i].y = sum;
    }
    ans = 8e18;
    sort(a, a + n, &cmp_x);
    rec(0, n - 1);
    printf("%I64d\n", ans);
    return 0;
}