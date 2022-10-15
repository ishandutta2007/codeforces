#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct voter
{
    ll p;
    ll m;
};
int cmp(voter a, voter b)
{
    if (a.m - b.m)
        return (a.m < b.m);
    return (a.p < b.p);
}

ll a, b, n, m, i, j, k, t;
ll dp[5010][5010];
vector<voter> lis;
voter h;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    vector<long long> odd, even;
    string s;
    char c;
    for (k = 1; k <= t; k++)
    {
       cin>>n>>m>>a>>b;
       cout<<((abs(a-b)+m<n)?abs(a-b)+m:n-1);
       cout<<endl;
    }
}