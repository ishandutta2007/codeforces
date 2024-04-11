//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
//#define double ld
using namespace std;
const ll mod=998244353;
const int N=300010;
int a[N];
int b[N];
int group[N];
map<int,int>r;
int mx[N];
int main()
{
//    freopen("fuel.in","r",stdin);
//    freopen("fuel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
 
    for (int i=1;i<=n;i++) cin>>a[i];
 
    for (int i=1;i<=m;i++) cin>>b[i];
    b[m+1]=1000000001;
    for (int i=1;i<=n;i++){
        group[i]=upper_bound(b+1,b+m+2,a[i])-b-1;
    }
 
    for (int i=1;i<=n;i++){
        if (!group[i]){
            cout<<0<<endl;
            return 0;
        }
        mx[group[i]]=i;
    }
    for (int i=1;i<m;i++){
        if (mx[i]>mx[i+1]){
            cout<<0<<endl;
            return 0;
        }
    }
    for (int i=1;i<=n;i++){
        r[a[i]]=i;
    }
    for (int i=1;i<=m;i++){
        if (!r[b[i]]){
            cout<<0<<endl;
            return 0;
        }
    }
    ll res=1ll;
    for (int i=1;i<m;i++){
        res*=((r[b[i+1]]-mx[i])*1ll);
        res%=mod;
    }
    cout<<res<<endl;
    return 0;
}
/*
3 4
1 3
5
9 2 7 7
6 1 0 9
4 7 4 6
*/