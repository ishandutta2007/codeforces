#include <bits/stdc++.h>
#define FOR(i, j, k) for (int i = j; i <= k; i ++)
#define FORD(i, j, k) for (int i = j; i >= k; i --)
#define mn 200005
#define maxC 1000000007
#define base 100007
#define F first
#define S second

using namespace std;
int n, temp[mn];

void setup()
{
    cin >> n;
    FOR(i, 1, n)
        cin >> temp[i];
    int dif = temp[2] - temp[1];
    FOR(i, 3, n)
    if (temp[i] - temp[i - 1] != dif)
    {
        cout << temp[n];
        return;
    }
    cout << temp[n] + dif;
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