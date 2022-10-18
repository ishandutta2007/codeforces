#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef double ld;
const int N = 30001;

vector<int> a;

int phi(int n)
{
    int ans = 0;
  //  cout << a.size() << endl;
    int x = a.size();
    for (int i = 1; i < (1 << x); i++)
    {
        int t = 1, q = 0;
        for (int j = 0; j < a.size(); j++)
            if (((1 << j) & i))
                t *= a[j], q ^= 1;
        if (q)
            ans += n / t;
        else
            ans -= n / t;
    }
    return n - ans;
}

int main()
{
  //  freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int ui = 0; ui < t; ui++)
    {
        int x, p, k;
        cin >> x >> p >> k;
        a.clear();
        for (int i = 2; i * i <= p; i++)
            if (p % i == 0)
            {
                while (p % i == 0)
                    p /= i;
                a.push_back(i);
            }
        if (p > 1)
            a.push_back(p);
        k += phi(x);
        int l = -1, r = 1e9;
        while (r - l > 1)
        {
            int mid = (r + l) / 2;
            if (phi(mid) < k)
                l = mid;
            else
                r = mid;
        }
        cout << r << " ";
    }
    return 0;
}