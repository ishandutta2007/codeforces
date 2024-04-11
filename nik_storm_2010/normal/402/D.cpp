#include<iostream>
#include<vector>

using namespace std;
const int N = 5000 + 50;

int a[N], b[N], n, m;

int find_prime(int x)
{
    int l = 0, r = m;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (b[m] >= x) r = m; else l = m;
    }
    if (b[r] == x) return -1; else return +1;
}

int gcd(int x, int y)
{
    if (y == 0) return x;
    return gcd(y, x % y);
}

int get(int x)
{
    int i = 2, res = 0;
    while (i * i <= x)
    {
        if (x % i == 0)
        {
            x /= i;
            res += find_prime(i);
        }
        else i++;
    }
    if (x != 1) res += find_prime(x);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) cin >> b[j];
    int res = 0;
    for (int i = n; i >= 1; i--)
    {
        int nod = a[1];
        for (int j = 2; j <= i; j++) nod = gcd(nod, a[j]);
        int all = get(nod);
        if (all < 0) for (int j = 1; j <= i; j++) a[j] /= nod;
        res += get(a[i]);
    }
    cout << res << endl;
    return 0;
}