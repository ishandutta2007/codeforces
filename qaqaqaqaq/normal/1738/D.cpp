#include<bits/stdc++.h>
#define int long long
using namespace std;


const int N=100007;
int n;
int a[N];
vector<int> lst[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        for (int i=1;i<=n;++i) cin>>a[i];
        for (int i=0;i<=n+2;++i) lst[i].clear();
        for (int i=1;i<=n;++i) lst[a[i]].push_back(i);
        int start=0;
        bool lg=0;
        if (lst[n+1].size()) start=n+1, lg=1;
        vector<int> ans;
        int mn=n+1, mx=0;
        while (1){
            int tmp=-1;
            for (auto c:lst[start]){
                if (lst[c].size()) tmp=c;
                else ans.push_back(c);
                if (lg^1) mn=min(mn,c);
                else mx=max(mx,c);
            }
            if (tmp==-1) break;
            ans.push_back(tmp);
            lg^=1, start=tmp;
        }
        cout<<mx<<"\n";
        for (auto c:ans) cout<<c<<" ";
        cout<<"\n";
    }
}