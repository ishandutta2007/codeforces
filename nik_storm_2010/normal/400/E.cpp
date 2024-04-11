#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
const int N = 200000;
const int L = 18;

set <int> one[L];
int a[N], leng[N][L];
long long k[N], sum;

void modify(int p, int x)
{
    for (int i = 0; i < L; i++)
    {
        int b1 = (x & (1 << i)) ? 1 : 0;
        int b2 = (a[p] & (1 << i)) ? 1 : 0;
        if (b1 == 1 && b2 == 1 || b1 == 0 && b2 == 0) continue;
        if (b1 == 1 && b2 == 0)
        {
            set <int>::iterator it1, it2;
            it2 = one[i].upper_bound(p);
            it1 = it2, it1--;
            int x1 = (*it1), x2 = (*it2), l1 = leng[x1][i], l2 = leng[x2][i];
            if (x1 + l1 == p && p + 1 == x2)
            {
                sum -= k[l1] * (1 << i) + k[l2] * (1 << i);
                one[i].erase(it2);
                leng[x1][i] = l1 + l2 + 1;
                sum += k[leng[x1][i]] * (1 << i);
                continue;
            }
            if (x1 + leng[x1][i] == p)
            {
                sum -= k[l1] * (1 << i);
                leng[x1][i] = l1 + 1;
                sum += k[leng[x1][i]] * (1 << i);
                continue;
            }
            if (p + 1 == x2)
            {
                sum -= k[l2] * (1 << i);
                one[i].erase(it2);
                leng[p][i] = l2 + 1;
                sum += k[leng[p][i]] * (1 << i);
                one[i].insert(p);
                continue;
            }
            one[i].insert(p);
            leng[p][i] = 1;
            sum += (1 << i);
        }
        else
        {
            set <int>::iterator it1 = one[i].upper_bound(p);
            it1--;
            int x1 = (*it1), l1 = leng[x1][i], l2;
            sum -= k[l1] * (1 << i);
            one[i].erase(it1);
            l2 = x1 + l1 - 1 - p;
            l1 = p - x1;
            if (l1 != 0)
            {
                one[i].insert(x1);
                leng[x1][i] = l1;
                sum += k[l1] * (1 << i);
            }
            if (l2 != 0)
            {
                one[i].insert(p + 1);
                leng[p + 1][i] = l2;
                sum += k[l2] * (1 << i);
            }
        }
    }
    a[p] = x;
}

int main()
{
    ios_base::sync_with_stdio(true);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < L; i++) one[i].insert(0), one[i].insert(n + 2);
    k[0] = 0;
    for (int i = 1; i < N; i++) k[i] = k[i - 1] + i;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        modify(i, x);
    }
    for (int i = 1; i <= m; i++)
    {
        int v, x;
        cin >> v >> x;
        modify(v, x);
        cout << sum << endl;
    }
    return 0;
}