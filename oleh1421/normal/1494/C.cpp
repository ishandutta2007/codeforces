//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//typedef __int128 ll;
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int a[N],b[N];
int suf[N];
int get(vector<int>u,vector<int>v){
    set<int>st;
    for (int i:v) st.insert(i);
    suf[u.size()]=0;
    for (int i=(int)u.size()-1;i>=0;i--){
        suf[i]=suf[i+1];
        if (st.find(u[i])!=st.end()) suf[i]++;
    }
    int res=suf[0];
    vector<int>vv;
    for (int i=0;i<u.size();i++){
        vv.push_back(u[i]-i);
    }
    for (int b:v){
        auto it=upper_bound(vv.begin(),vv.end(),b);
        int pos=it-vv.begin();
        int cnt=upper_bound(v.begin(),v.end(),b+pos-1)-lower_bound(v.begin(),v.end(),b);
//        cout<<b<<" "<<pos<<" "<<cnt<<endl;
        res=max(res,suf[pos]+cnt);
    }
    return res;
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    vector<int>x,y,u,v;
    for (int i=1;i<=n;i++){
        if (a[i]<0) x.push_back(-a[i]);
        else u.push_back(a[i]);

    }
    for (int i=1;i<=m;i++){
        if (b[i]<0) y.push_back(-b[i]);
        else v.push_back(b[i]);
    }
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    cout<<get(x,y)+get(u,v)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}