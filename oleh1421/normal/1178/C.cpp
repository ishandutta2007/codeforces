#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define MINX(a,b) if (a>b) a=b;
#define MAXX(a,b) if (a<b) a=b;
#define endl '\n'
typedef long long ll;
using namespace std;
int a[1000010];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;cin>>a>>b;
    ll res=1ll;
    for (int i=1;i<=a+b;i++){
        res*=2ll;
        res%=998244353ll;
    }
    cout<<res;
    return 0;
}
/*
6 3
18 75 245 847 1859 26
*/