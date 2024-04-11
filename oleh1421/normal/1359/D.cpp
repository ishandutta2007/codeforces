//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
ll a[N];
ll res=0ll;
ll solve(int l,int r){
    ll sum=0ll;
    ll mx=-1000000001ll;
    for (int i=l;i<=r;i++){
        sum=max(sum,0ll);
        sum+=a[i];
        mx=max(mx,sum);
    }
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int x=-30;x<=30;x++){
        int l=1;
        for (int i=1;i<=n;i++){
            if (a[i]>x){
                res=max(res,solve(l,i-1)-x);
                l=i;
            }
            if (a[i]>x && l==i) l++;
        }
        res=max(res,solve(l,n)-x);
    }
    cout<<res<<endl;
    return 0;
}
/*
4
0100
1110
0101
0111
*/