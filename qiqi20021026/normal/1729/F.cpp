#include<bits/stdc++.h>

using namespace std;

int n,m,w,pre[300000];
string st;

void solve(){
    cin>>st; n=st.size();
    cin>>w>>m;
    vector<int> f[10];
    for (int i=1;i<=n;++i){
        pre[i]=(pre[i-1]+st[i-1]-'0')%9;
        if (i>=w){
            int t=(pre[i]-pre[i-w]+9)%9;
            if (f[t].size()<2) f[t].push_back(i-w+1);
        }
    }
    while (m--){
        int x,y,z; cin>>x>>y>>z;
        int s=(pre[y]-pre[x-1]+9)%9;
        int a1=-1,a2=-1;
        for (int i=0;i<9;++i) for (int u:f[i]){
            for (int j=0;j<9;++j) for (int v:f[j]){
                if (u!=v&&(i*s+j)%9==z){
                    if (a1==-1){
                        a1=u,a2=v;
                    }
                    if (u<a1){
                        a1=u,a2=v;
                    }
                    if (u==a1&&v<a2){
                        a1=u,a2=v;
                    }
                }
            }
        }
        cout<<a1<<' '<<a2<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();

    return 0;
}