#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int query(int pos)
{
    cout << "? " << pos << endl;
    int k;
    cin >> k;
    return k;
}

int mod(int n, int k)
{
    n--;
    int ans = (n % k + k) % k;
    return ans + 1;
}

bool same(int a, int b, int target)
{
    if (a > target)
        return b > target;
    return b < target;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
        perm[i] = i + 1;
    int ind = -1;
    int val = 0;
    shuffle(perm.begin(), perm.end(), rng);
    for (int i = 0; i < n; i++)
    {
        val = query(perm[i]);
        if (val != k)
        {
            ind = perm[i];
            break;
        }
    }
    int dir = val > k ? -1 : 1;
    int newval = 0;
    int maxjump = 0;
    for (int i = 1; i <= n; i <<= 1)
    {
        newval = query(mod(ind + i * dir, n));
        if (!same(val, newval, k))
        {
            maxjump = i;
            break;
        }
    }
    int curjump = 0;
    for (int jump = maxjump; jump; jump >>= 1)
    {
        while (curjump + jump <= maxjump)
        {
            newval = query(mod(ind + (curjump + jump) * dir, n));
            if (same(val, newval, k))
                curjump += jump;
            else
                break;
        }
    }
    ind = mod(ind + curjump * dir, n);
    ind = mod(ind + dir, n);
    cout << "! " << ind << endl;
    return 0;
}