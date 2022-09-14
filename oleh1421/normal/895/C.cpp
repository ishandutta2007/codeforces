//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC opitmize ("trapv")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
bool used[1010];
const int N=100010;
int a[N];
int32_t main()
{
//
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i=2;i<=70;i++) used[i]=true;
    for (int i=2;i*i<=70;i++){
        for (int j=i*i;j<=70;j+=i) used[j]=false;
    }
    vector<int>p;
    for (int i=2;i<=70;i++) if (used[i]) p.push_back(i);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        for (int j=0;j<p.size();j++){
            int cn=0;
            while (x%p[j]==0){
                cn++;
                x/=p[j];
            }
            if (cn%2) a[i]^=(1<<j);
        }
    }
    vector<int>basis;
    for (int i=1;i<=n;i++){
        for (auto y:basis){
            a[i]=min(a[i],a[i]^y);
        }
        if (a[i]) basis.push_back(a[i]);
    }
    ll res=1ll;
    for (int i=1;i<=n-basis.size();i++){
        res=(res+res)%1000000007;
    }
    cout<<res-1;
    return 0;
}