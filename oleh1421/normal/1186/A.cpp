#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int>g[10000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;cin>>n>>m>>k;
    if (n<=min(m,k)) cout<<"Yes";
    else cout<<"No";
    return 0;
}