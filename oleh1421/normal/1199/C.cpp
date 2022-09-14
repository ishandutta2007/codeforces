#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
using namespace std;
int a[1000001];
ll s[1000001];
map<int,int>cnt;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,I;cin>>n>>I;
    I*=8;
    set<int>st;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        cnt[a[i]]++;
        st.insert(a[i]);
    }
    int k=0;
    for (auto i:st){
        a[++k]=i;
    }
    I/=n;
    if (I>=20){
        cout<<0;
        return 0;
    }
    int x=(1<<I);
    if (x>=k){
        cout<<0;
        return 0;
    }
    s[0]=0ll;
    for (int i=1;i<=k;i++){
        s[i]=s[i-1]+cnt[a[i]];
    }
    ll res=n;
    for (int l=0;l<=k-x;l++){
         res=min(res,s[l]+s[k]-s[l+x]);
    }
    cout<<res;
    return 0;
}