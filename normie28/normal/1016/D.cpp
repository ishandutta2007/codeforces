#pragma optimization_level 3
#include<bits/stdc++.h>
#define fst cin.tie(0);cin.sync_with_stdio(0);cout.tie(0);cout.sync_with_stdio(0)
using namespace std;
typedef long long ll;
 
 
const ll mod=1000000007;
const ll MAX=222222;
const ll MAXD=411111;
const ll INF=1e18;
 
const long double EPS = 1e-13;
int a[MAX];
int b[MAX];
 
signed main()
{
    fst;
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i < n;i ++)
        cin >> a[i], cnt ^= a[i];
    for(int i = 0; i < m; i++)
    {
        cin >> b[i]; cnt ^= b[i];
    }
    if (cnt != 0)
    {
        cout << "NO";
        return 0;
    }
    cout << " YES" << endl;
    for(int i = 1; i < m; i++)
    {
        cnt ^= b[i];
    }
    cnt ^= a[0];
    cout << cnt << " ";
    for(int i = 1; i < m; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    for(int i = 1; i < n; i++)
    {
        cout << a[i] << " ";
        for(int j = 1; j < m; j++)
        {
            cout << 0 << " ";
        }
    }
}