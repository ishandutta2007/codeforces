#include <bits/stdc++.h>
#define FOR(i, j, k) for (int i = j; i <= k; i ++)
#define FORD(i, j, k) for (int i = j; i >= k; i --)
#define mn 600005
#define maxC 1000000007
#define base 100007
#define F first
#define S second

using namespace std;
long long n, k;
char s[mn];

long long sumFromOne(long long to)
{
    return ((to + 1) * to) >> 1;
}

void printAns(int start, int finish, long long k)
{
    if (start > finish)
        return;

    s[start] = '(';
    int add = min(1ll * (finish - start + 1) / 2 - 1, k);

    int end = start + add * 2 + 1;
    s[end] = ')';
    for(int i = end + 1; i <= finish; i += 2)
    {
        s[i] = '(';
        s[i + 1] = ')';
    }

    printAns(start + 1, end - 1, k - add);
}

void setup()
{
    cin >> n >> k;
    if (k > sumFromOne(n - 1))
    {
        cout << "Impossible";
        exit(0);
    }
    printAns(1, n * 2, k);
    FOR(i, 1, n * 2)
        cout << s[i];
}

void xuly ()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    setup ();
    xuly ();
    return 0;
}