//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
int p[N];
int l[N],r[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    l[1]=0;
    for (int i=2;i<=n;i++){
        if (p[i-1]>p[i]) l[i]=0;
        else l[i]=l[i-1]+1;
    }
    r[n]=0;
    for (int i=n-1;i>=1;i--){
        if (p[i+1]>p[i]) r[i]=0;
        else r[i]=r[i+1]+1;
    }
    int mx=0;
    for (int i=1;i<=n;i++){
        mx=max(mx,l[i]);
        mx=max(mx,r[i]);
    }
    vector<int>v;
    for (int i=1;i<=n;i++){
        if (l[i]==mx || r[i]==mx) v.push_back(i);
    }
    if (v.size()>1){
        cout<<0<<endl;
        return;
    }
    int ind=v[0];
//    cout<<l[ind]<<" "<<r[ind]<<endl;
    if (l[ind]<=1 || r[ind]<=1 || l[ind]!=r[ind]){
        cout<<0<<endl;
        return;
    }
    cout<<(mx+1)%2<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
4
1 2 2 2
*/