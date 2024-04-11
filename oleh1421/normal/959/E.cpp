//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC opitmize ("trapv")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=300010;
int a[N];
vector<int>basis[N];
int pow2[N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;cin>>n;
    n--;
    ll res=0ll;
    for (int i=0;i<=40;i++){
        res+=((n+1ll)/2ll)*(1ll<<i);
        n/=2ll;
    }
    cout<<res;
    return 0;
}
/*
2
4
0 0
2 0
6 5
4 5
5
6 0
9 0
11 2
11 4
8 5
2
1 2
2 1
*/