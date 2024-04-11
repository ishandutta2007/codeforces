#include <bits/stdc++.h>
#define FOR(i, j, k) for (int i = j; i <= k; i ++)
#define FORD(i, j, k) for (int i = j; i >= k; i --)
#define mn 200005
#define maxC 1000000007
#define base 100007
#define F first
#define S second

using namespace std;
int n, cnt[10];

void setup()
{
    cin >> n;
    char c;
    FOR(i, 1, n)
    FOR(j, 1, 7)
    {
        cin >> c;
        cnt[j] += c - '0';
    }
    int ans = 0;
    FOR(i, 1, 7)
        ans = max(ans, cnt[i]);
    cout << ans;
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