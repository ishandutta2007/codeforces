#include<bits/stdc++.h>

using namespace std;

#define N 1200

int d[N],p[N],fa[N];

int gfa(int x){return x==fa[x]?x:fa[x]=gfa(fa[x]);}
int qry(int x){
    cout<<"? "<<x<<'\n';
    fflush(stdout);
    cin>>x;
    return x;
}
void solve(){
    int n; cin>>n;
    for (int i=1;i<=n;++i) cin>>d[i];
    for (int i=1;i<=n;++i) p[i]=i;
    sort(p+1,p+n+1,[&](int x,int y){return d[x]>d[y];});
    for (int i=1;i<=n;++i) fa[i]=i;
    for (int i=1;i<=n;++i){
        int x=p[i];
        if (x!=fa[x]) continue;
        for (int j=1;j<=d[x];++j){
            int y=qry(x);
            if (y==fa[y]) fa[y]=x;
            else{
                fa[x]=y;
                break;
            }
        }
    }
    cout<<"! "; for (int i=1;i<=n;++i) cout<<gfa(i)<<" \n"[i==n];
    fflush(stdout);
}
int main(){
    int T; cin>>T;
    while (T--) solve();
}