//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
int a[N],b[N],c[N];
set<pair<int,int> >st[N];
int x[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=m;i++) cin>>c[i];
    for (int i=0;i<=n;i++) st[i].clear();
    for (int i=1;i<=n;i++) st[b[i]].insert({(a[i]==b[i]),i});
    for (int i=m;i>=1;i--){
        if (st[c[i]].empty() && st[0].empty()){
            cout<<"NO\n";
            return;
        }
        if (st[c[i]].empty()){
            int pos=(*st[0].begin()).second;
            x[i]=pos;
            continue;
        }
        int pos=(*st[c[i]].begin()).second;
        st[c[i]].erase(st[c[i]].begin());
        x[i]=pos;
        a[pos]=c[i];
//        cout<<pos<<endl;
        st[0].insert({0,pos});
    }
    for (int i=1;i<=n;i++){
        if (a[i]!=b[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for (int i=1;i<=m;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;

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
/*
1
5 2
1 2 2 1 1
1 2 2 1 1
1 2
*/