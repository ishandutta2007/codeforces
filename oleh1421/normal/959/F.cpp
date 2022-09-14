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
    int n,tt;cin>>n>>tt;
    pow2[0]=1;
    for (int i=1;i<=n;i++){
        pow2[i]=(pow2[i-1]*2)%1000000007;
    }
    for (int i=1;i<=n;i++) cin>>a[i];
    basis[0]={};
    for (int i=1;i<=n;i++){
        basis[i]=basis[i-1];
        for (auto cur:basis[i]){
            a[i]=min(a[i],a[i]^cur);
        }
        if (a[i]) basis[i].push_back(a[i]);
    }
    while (tt--){
        int l,x;cin>>l>>x;
        for (auto cur:basis[l]) x=min(x,x^cur);
        if (x) cout<<0<<endl;
        else cout<<pow2[l-basis[l].size()]<<endl;
    }
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