//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
#define double ld
using namespace std;
const int N=500010;
int a[N];
int b[N];
map<int,int>mp;
vector<int> ga[N];
vector<int> gb[N];
void solve(){
    int n;cin>>n;
    set<int>st;
    mp.clear();
    vector<int>v,u;
    for (int i=1;i<=n;i++) cin>>a[i],st.insert(a[i]),v.push_back(a[i]);
    for (int i=1;i<=n;i++) cin>>b[i],st.insert(b[i]),u.push_back(b[i]);
    sort(v.begin(),v.end());
    sort(u.begin(),u.end());
    if (v!=u){
        cout<<"No\n";
        return;
    }
    int cnt=0;
    for (auto i:st) mp[i]=++cnt;
    if (cnt>n){
        cout<<"No\n";
        return;
    }
    for (int i=1;i<=n;i++) a[i]=mp[a[i]];
    for (int i=1;i<=n;i++) b[i]=mp[b[i]];
//    for (int i=0;i<=n;i++){
//        cnt[i]=cnt1[i]=0;
//    }
    if (n%2 && a[n/2+1]!=b[n/2+1]){
        cout<<"No\n";
        return;
    }
    for (int i=1;i<=n/2;i++){
        if (a[i]>a[n-i+1]) swap(a[i],a[n-i+1]);
        if (b[i]>b[n-i+1]) swap(b[i],b[n-i+1]);
    }
    for (int i=0;i<=n;i++) ga[i].clear(),gb[i].clear();
    for (int i=1;i<=n/2;i++){
        ga[a[i]].push_back(i);
        gb[b[i]].push_back(i);
    }
    for (int i=1;i<=n;i++){
        vector<int>x;
        vector<int>y;
        for (auto j:ga[i]) x.push_back(a[n-j+1]);
        for (auto j:gb[i]) y.push_back(b[n-j+1]);
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        if (x!=y){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}
int main()
{

//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}