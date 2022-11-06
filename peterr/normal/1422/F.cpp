#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MAXA = 2E5;
const int MOD = 1E9 + 7;
vector<vector<int>> lowPrimes;
int a[MAXN];
int smallestPrime[MAXA + 1];
vector<int> primes;
vector<vector<int>> powPrime;
map<int, int> id;
vector<pair<int, int>> bigPrimes[MAXN * 2];
int nxtLeft[MAXN];

int binSearch(vector<pair<int, int>> &vec, int cutoff)
{
    int ans = -1;
    for (int jump = (int) vec.size() / 2 + 1; jump; jump >>= 1)
    {
        while (ans + jump < (int) vec.size() && vec[ans + jump].first < cutoff)
            ans += jump;
    }
    if (ans == -1)
        return 1;
    return vec[ans].second;
}

int query2(int l, int r, int leftRange, int n)
{
    l += n;
    r += n;
    int ans = 1;
    while (l <= r)
    {
        if (l & 1)
        {
            ans = (int) ((long long) ans * binSearch(bigPrimes[l], leftRange) % MOD);
            l++;
        }
        if (!(r & 1))
        {
            ans = (int) ((long long) ans * binSearch(bigPrimes[r], leftRange) % MOD);
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

void buildTree(int ind, int n)
{
    if (ind >= n)
    {
        if (a[ind - n] > 1)
        {
            bigPrimes[ind].push_back(make_pair(nxtLeft[ind - n], a[ind - n]));
        }
    }
    else
    {
        buildTree(ind * 2, n);
        buildTree(ind * 2 + 1, n);
        int ptr1 = 0;
        int ptr2 = 0;
        while (ptr1 < (int) bigPrimes[ind * 2].size() && ptr2 < (int) bigPrimes[ind * 2 + 1].size())
        {
            if (bigPrimes[ind * 2][ptr1].first < bigPrimes[ind * 2 + 1][ptr2].first)
            {
                bigPrimes[ind].push_back(bigPrimes[ind * 2][ptr1]);
                ptr1++;
            }
            else
            {
                bigPrimes[ind].push_back(bigPrimes[ind * 2 + 1][ptr2]);
                ptr2++;
            }
        }
        while (ptr1 < (int) bigPrimes[ind * 2].size())
        {
            bigPrimes[ind].push_back(bigPrimes[ind * 2][ptr1]);
            ptr1++;
        }
        while (ptr2 < (int) bigPrimes[ind * 2 + 1].size())
        {
            bigPrimes[ind].push_back(bigPrimes[ind * 2 + 1][ptr2]);
            ptr2++;
        }
    }
}

int query(vector<int> &seg, int l, int r, int n)
{
    l += n;
    r += n;
    int ans = seg[l];
    while (l <= r)
    {
        if (l & 1)
            ans = max(ans, seg[l++]);
        if (!(r & 1))
            ans = max(ans, seg[r--]);
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

void inc(vector<int> &seg, int pos, int amt, int n)
{
    pos += n;
    seg[pos] += amt;
    pos >>= 1;
    while (pos)
    {
        seg[pos] = max(seg[pos * 2], seg[pos * 2 + 1]);
        pos >>= 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i <= MAXA; i++)
    {
        if (!smallestPrime[i])
        {
            smallestPrime[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < (int) primes.size(); j++)
        {
            if (primes[j] * i > MAXA)
                break;
            smallestPrime[primes[j] * i] = primes[j];
            if (i % primes[j] == 0)
                break;
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < (int) primes.size(); i++)
    {
        if (primes[i] * primes[i] > MAXA)
            break;
        id[primes[i]] = i;
        lowPrimes.push_back(vector<int>(2 * n, 0));
        powPrime.push_back(vector<int>(21, 1));
        for (int j = 1; j <= 20; j++)
        {
            powPrime[i][j] = (int) ((long long) powPrime[i][j - 1] * primes[i] % MOD);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        while (a[i] > 1)
        {
            int p = smallestPrime[a[i]];
            if ((long long) p * p > MAXA)
                break;
            int cnt = 0;
            while (a[i] % p == 0)
            {
                cnt++;
                a[i] /= p;
            }
            inc(lowPrimes[id[p]], i, cnt, n);
        }
    }
    map<int, int> seen;
    for (int i = 0; i < n; i++)
    {
        nxtLeft[i] = -1;
        if (seen.count(a[i]))
        {
            nxtLeft[i] = seen[a[i]];
        }
        seen[a[i]] = i;
    }
    buildTree(1, n);
    for (int i = 1; i < 2 * n; i++)
    {
        /*
        cout << "seg " << i << endl;
        for (pair<int, int> jj : bigPrimes[i])
            cout << jj.first << " " << jj.second << endl;
        cout << "done" << endl;
        cout << endl;
        */
        if (bigPrimes[i].empty())
            continue;
        int cur = bigPrimes[i][0].second;
        for (int j = 1; j < (int) bigPrimes[i].size(); j++)
        {
            cur = (int) ((long long) cur * bigPrimes[i][j].second % MOD);
            bigPrimes[i][j].second = cur;
        }
    }
    int q;
    cin >> q;
    int ans = 0;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x = (ans + x) % n;
        y = (ans + y) % n;
        if (x > y)
            swap(x, y);
        ans = 1;
        for (int i = 0; i < (int) lowPrimes.size(); i++)
        {
            int cnt = query(lowPrimes[i], x, y, n);
            ans = (int) ((long long) ans * powPrime[i][cnt] % MOD);
        }
        ans = (int) ((long long) ans * query2(x, y, x, n) % MOD);
        cout << ans << "\n";
    }
    return 0;
}