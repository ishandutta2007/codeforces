#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 1E6;
int boxes[MAXN];
int temp[MAXN];
bool isPrime[MAXN + 1];
vector<long long> primes;

long long solve(long long d, int n)
{
    for (int i = 0; i < n; i++)
    {
        boxes[i] = temp[i];
    }
    long long cost = 0;
    int ptr = 0;
    while (ptr < n && boxes[ptr] == 0)
        ptr++;
    while (ptr < n)
    {
        boxes[ptr] = boxes[ptr] % d;
        while (ptr < n && boxes[ptr] == 0)
            ptr++;
        if (ptr >= n)
            break;
        int ptr2 = ptr;
        long long cnt = 0;
        long long last = 0;
        while (ptr2 < n && cnt < d)
        {
            if (cnt + boxes[ptr2] < d)
            {
                cnt += boxes[ptr2];
                ptr2++;
            }
            else
            {
                last = d - cnt;
                cnt = d;
            }
        }
        int med = ptr;
        long long half = (d + 1) / 2;
        while (half > 0)
        {
            half -= boxes[med];
            if (half > 0)
                med++;
        }
        for (int i = ptr; i < ptr2; i++)
        {
            cost += (long long) boxes[i] * abs(med - i);
            boxes[i] = 0;
        }
        cost += (long long) last * abs(ptr2 - med);
        boxes[ptr2] -= last;
        while (ptr < n && boxes[ptr] == 0)
            ptr++;
    }
    return cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(isPrime + 2, isPrime + MAXN + 1, true);
    for (int i = 2; i <= MAXN; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            if ((long long) i * i <= MAXN)
            {
                for (int j = i * i; j <= MAXN; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> boxes[i];
        sum += boxes[i];
        temp[i] = boxes[i];
    }
    long long ans = 3E18;
    bool found = false;
    for (long long d : primes)
    {
        if (sum % d == 0)
        {
            ans = min(ans, solve(d, n));
            while (sum % d == 0)
                sum /= d;
        }
    }
    if (sum > 1)
        ans = min(ans, solve(sum, n));
    if (ans == (long long) 3E18)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}