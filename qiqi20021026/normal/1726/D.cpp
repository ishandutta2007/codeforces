#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,m,a[N],b[N],gg[N];

struct kruskal{
    int fa[N];
    int gfa(int x){return x==fa[x]?x:fa[x]=gfa(fa[x]);}
    int merge(int x,int y){
        x=gfa(x); y=gfa(y);
        if (x==y) return 0;
        fa[x]=y;
        return 1;
    }
    void clear(int n){
        for (int i=1;i<=n;++i) fa[i]=i;
    }
}t1,t2;

void solve(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>a[i]>>b[i];
        gg[i]=0;
    }
    vector<int> q;
    t1.clear(n);
    for (int i=1;i<=m;++i){
        int x=a[i],y=b[i];
        if (!t1.merge(x,y)){
            q.push_back(i);
            gg[i]=1;
        }
    }
    int k=m-n+1;
    string ans(m,'0'); int num=0;
    for (int s=0;s<1<<k;++s){
        t1.clear(n); t2.clear(n);
        string st(m,'0'); int cnt=0;
        for (int i=0;i<k;++i){
            if (s>>i&1){
                cnt+=t1.merge(a[q[i]],b[q[i]]);
                st[q[i]-1]='0';
            }
            else{
                cnt+=t2.merge(a[q[i]],b[q[i]]);
                st[q[i]-1]='1';
            }
        }
        for (int i=1;i<=m;++i){
            if (!gg[i]){
                if (t1.merge(a[i],b[i])){
                    ++cnt;
                    st[i-1]='0';
                }
                else{
                    st[i-1]='1';
                    cnt+=t2.merge(a[i],b[i]);
                }
            }
        }
        if (cnt>num){
            num=cnt;
            ans=st;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();

    return 0;
}